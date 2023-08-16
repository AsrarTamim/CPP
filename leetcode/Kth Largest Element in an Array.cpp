class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        int mn = *min_element(nums.begin(),nums.end());
        int N = 2*mx+1;
        map<int,int>hash;
        for(auto x : nums){
            hash[x + mx]++;
        }
       
        int i;
        for(i = mx+mx; i >= mn+mx;){
            if(hash[i] == 0) {i--;continue;}
            k-= hash[i];
            if(k <= 0) return i - mx;
            i--;
        }
        
        return -1;
    }
};