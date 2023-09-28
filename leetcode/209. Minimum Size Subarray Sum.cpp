class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int n = nums.size();
        int pre[n+1];
        pre[0] = 0;
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i-1] +nums[i-1];
        }

        int mn = 1e9;
        int j=1;
        int x;
        for(int i = 1; i <= n; i++){
             x = pre[i];
            
            while(x >= t){
                mn = min(mn,i - j + 1);
                x = pre[i] - pre[j];
                j++;
                
            }
        }
        if(mn == 1e9) mn = 0;
        return mn;
    }
};