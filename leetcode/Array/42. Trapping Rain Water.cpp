class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int left_max = h[0];
        int right_max = h[n-1];
        int l = 1;
        int r = n-2;
        int ans = 0;
        while(l <= r){
            if(h[l] >= left_max){
                left_max = h[l];
                l++;
            }
            else if(h[r] >= right_max) {
                right_max = h[r];
                r--;
            }
            else if(left_max <= right_max){
                ans += left_max  - h[l];
                l++;
            }
            else{
                ans += right_max - h[r]; 
                r--;
            }
        }
        return ans;
    }
};