class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        for(int i = 0; i <n-2; i++){
            int j= i+1;
            int k = n-1;
            while(j < k){
                int sum =  nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    vector<int>ans(3);
                    ans[0] = nums[i];
                    ans[1] = nums[j];
                    ans[2] = nums[k];
                    s.insert(ans);
                    k--; j++;
                }
                else if(sum < 0) j++;
                else k--;
                    
                }
        }
        vector<vector <int> >result (s.begin(), s.end());
        return result;
    }
};