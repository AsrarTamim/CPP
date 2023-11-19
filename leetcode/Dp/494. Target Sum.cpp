  const int N = 2e4+10, inf = 1e9 + 9;
int dp[22][N];
int cnt = 0;
int x = 1000;
int y = 0;
int fun(int i ,vector<int>& nums,int target, int n){
    if(i == n){
        if(target == 0) {
            y = 1;return y;
        }
        else {
            y = 0;
            return y;
        }
    }
    int &ans = dp[i][target + x];
    if(dp[i][target + x] != - 1) return dp[i][target + x];

    int temp1 = fun(i+1,nums,target - nums[i],n);
    int temp2 = fun(i+1,nums,target + nums[i],n);

    dp[i][target + x] = temp1 + temp2;
    return dp[i][target + x];
}
class Solution {
public:
  

int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof dp);
        fun(0,nums,target,nums.size());
        return dp[0][target+x];
        
    }

};