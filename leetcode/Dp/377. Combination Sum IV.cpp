const int N = 1e5 + 10;
int dp[N];

// Recursive function to compute the number of combinations to reach the target
int d(vector<int>& ar, int target) {
    // Base case: If the target is negative, no valid combinations
    if (target < 0) {
        return 0;
    }
    // Base case: If the target is zero, one valid combination (empty subset)
    if (target == 0) {
        return 1;
    }
    // Check if the result for the current target has already been computed
    int &ans = dp[target];
    if (ans != -1) {
        return ans;
    }
    ans = 0;

    // Iterate through the array of numbers to find combinations
    for (int i = 0; i < ar.size(); i++) {
        // Recursively compute combinations for the remaining target
        ans += d(ar, target - ar[i]);
    }
    // Memoize the result for the current target
    dp[target] = ans;
    return ans;
}

class Solution {
public:
    // Function to compute the combination sum for a given target using the 'd' function
    int combinationSum4(vector<int>& nums, int target) {
        // Initialize the dp array with -1 to mark that values haven't been computed yet
        memset(dp, -1, sizeof dp);
        // Return the result obtained from the 'd' function
        return d(nums, target);
    }
};
