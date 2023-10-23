class Solution {
public:
    int subarraysDivByK(vector<int>& v, int k) {
        int n = v.size();
        
        // `pre` will store the prefix sum.
        // pre[i] represents sum of elements from index 0 to i-1.
        vector<int> pre(n + 1, 0);
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i-1] + v[i-1];
        }
        
        // `freq` will store the frequency of remainders.
        // The idea is, if two numbers a and b have the same remainder when 
        // divided by k, then their difference a-b is divisible by k.
        vector<int> freq(k, 0);
        
        int ans = 0;
        // We initialize freq[0] to 1 because any prefix sum 
        // divisible by k will have a remainder of 0.
        // So, for each such prefix sum, we'll get a valid subarray 
        // (from the start to current index).
        freq[0] = 1;
        
        for(int i = 1; i <= n; i++){
            // If prefix sum is negative, make it positive by adding k.
            // For example, -2 % 5 = -2. But (-2+5) % 5 = 3, which is positive.
            if(pre[i] < 0)
                pre[i] = (pre[i] % k) + k;
            
            // Update prefix sum to store remainder instead of actual sum.
            pre[i] %= k;
            
            // `freq[pre[i]]` tells us the number of prefix sums encountered
            // so far with the same remainder as `pre[i]`. If we have seen 
            // the same remainder before, we can form `freq[pre[i]]` subarrays 
            // ending at current index which will be divisible by k.
            ans += freq[pre[i]];
            
            // Increase the count of current remainder in freq.
            freq[pre[i]]++;
        }
        return ans;
    }
};
