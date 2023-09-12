class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        int pre[n+1];
        memset(pre, 0, sizeof pre);
        for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + nums[i-1];
        
        map<int,int>mp;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(pre[i] == k) ans++;
            if(mp.find(pre[i] - k) != mp.end()){
                ans += mp[pre[i] - k];
            }
            mp[pre[i]]++;
        }
    return ans;

    }
};