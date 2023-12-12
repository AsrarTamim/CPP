class Solution {
public:
    int maxi = 0;

    // Recursive function to solve the House Robber problem
    int solve(int i, vector<int> arr, vector<int> &dp) {
        // Base case: If we are at the last house, return its value
        if (i == arr.size() - 1) return arr[arr.size() - 1];
        
        // Base case: If we go beyond the last house, return 0
        if (i >= arr.size()) return 0;
        
        // If the value for the current index is already calculated, return it
        if (dp[i] != -1) return dp[i];

        // Calculate the maximum amount of money for the current house
        int not_pick = solve(i + 1, arr, dp) + 0;  // Skip the current house
        int pick = solve(i + 2, arr, dp) + arr[i];  // Pick the money from the current house

        // Update the dp array with the maximum amount
        dp[i] = max(pick, not_pick);

        return dp[i];
    }

    // Main function to calculate the maximum amount of money that can be robbed
    int rob(vector<int> &nums) {
        // Initialize a memoization array with -1
        vector<int> dp(400, -1);

        // Call the solve function starting from the first house
        return solve(0, nums, dp);
    }
};