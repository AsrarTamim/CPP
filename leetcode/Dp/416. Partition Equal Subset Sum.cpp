/*
    The Solution class defines a method canPartition, which determines whether a given vector of integers (nums) can be partitioned into two subsets with equal sum. The algorithm calculates the sum of all elements in the vector and checks if it's even. If not, it returns false since equal partitioning is not possible.

    The private helper method dp is responsible for the recursive dynamic programming approach to solve the problem. It uses memoization to store previously computed results and avoid redundant calculations. The function explores two possibilities at each step: taking or not taking the current element into the subset. The result is cached in the memo table to optimize subsequent calls.

    Overall, this algorithm efficiently utilizes dynamic programming to find a solution to the equal subset partition problem, making use of memoization to enhance performance.
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<vector<int>> memo(nums.size(), vector<int>(target+1, -1));
        return dp(nums, target, 0, memo);
    }

private:
    bool dp(vector<int>& nums, int target, int idx, vector<vector<int>>& memo) {
        if (idx == nums.size()) return false;
        if (nums[idx] == target) return true;
        if (memo[idx][target] != -1) return memo[idx][target];

        int take = false;
        if (target > nums[idx]) take = dp(nums, target - nums[idx], idx + 1, memo);
        int notTake = dp(nums, target, idx + 1, memo);
        return memo[idx][target] = take || notTake;
    }
};
