class Solution {
public:
    void sortColors(vector<int>& ar) {
        // `low` and `mid` pointers start from the beginning, while `high` starts from the end.
        int low = 0, mid = 0, high = ar.size()-1;

        // Process elements until the mid pointer crosses the high pointer.
        while(mid <= high){
            // If the current element at the `mid` pointer is 0, swap it with the element at the `low` pointer.
            // This is because we want all the 0s to be at the beginning.
            if(ar[mid] == 0){
                swap(ar[mid], ar[low]);
                mid++;
                low++;
            }
            // If the element is 1, we don't need to move it, just move to the next element.
            else if(ar[mid] == 1){
                mid++;
            }
            // If the current element at the `mid` pointer is 2, swap it with the element at the `high` pointer.
            // This is because we want all the 2s to be at the end.
            else{
                swap(ar[mid],ar[high]);
                high--;
            }
        }
    }
};
