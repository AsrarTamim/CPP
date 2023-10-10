class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size() > b.size()) return findMedianSortedArrays(b,a);

   int n = a.size(), m = b.size();
        int median = (m+n+1)/2;
        int left = 0, right = n;
        int i,j;

        while(left <= right){
            int mid = (left + right) /2;
            int i = mid; 
            int j = median - mid;
            
            int l1,l2,r1,r2;
            if(i == 0) l1 = INT_MIN;
            else l1 = a[i-1];
            if(j == m) r2 = INT_MAX;
            else r2 = b[j];
            if(i == n) r1 = INT_MAX;
            else r1 = a[i];
            if(j == 0) l2 = INT_MIN;
            else l2 = b[j-1];
            
            if(l1 <= r2 and r1 >= l2){ 
                if((n+m) % 2 == 0) { 
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else{ 
                    return max(l1,l2);
                }
            }
            else{
                if(l2 > r1) left = mid+1;
                else right = mid - 1;
            }
         } return 0;

    }
};