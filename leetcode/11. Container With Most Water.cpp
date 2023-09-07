class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int l = 0, r = n - 1;
        int mx = 0;
        while(l < r){
            int mn = min(h[l],h[r]);
            mx = max(mx, mn * (r - l));
            if(h[l] < h[r]) l++;
            else r--;
        }
        return mx;
    }
};