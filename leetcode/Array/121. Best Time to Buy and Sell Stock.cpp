class Solution {
public:
    int maxProfit(vector<int>& a) {
        
       int mn = a[0], mx_prof = 0, n = a.size();

       for(int i = 1; i < n; i++){
           mx_prof = max(mx_prof, a[i] - mn);
           mn = min(a[i],mn);
       }
        return mx_prof;
    }
};