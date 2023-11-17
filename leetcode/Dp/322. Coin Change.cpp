// Helper function that uses recursion and memoization to find the minimum number of coins.
int coinChangeRecursiveDP(const vector<int>& coins, int amount, vector<int>& dp) {
    // If the amount is 0, no coins are needed.
    if (amount == 0) return 0;
    
    // If the amount is negative, it is not possible to form that amount with any combination of coins.
    if (amount < 0) return INT_MAX; 
    
    // If we have already computed the minimum coins for this amount, return the stored result.
    if (dp[amount] != -1) return dp[amount];
    
    // Initialize the minimum number of coins to infinity.
    int minCoins = INT_MAX;
    for (int coin : coins) {
        // We only proceed if the amount is greater than or equal to the coin value.
        if (amount >= coin) {
            // Recurse with the remaining amount after choosing the coin.
            int result = coinChangeRecursiveDP(coins, amount - coin, dp);
            // If a result is found, take the minimum of the current minimum and the result plus one (for the chosen coin).
            if (result != INT_MAX) {
                minCoins = min(minCoins, result + 1);
            }
        }
    }
    
    // Save the computed result for this amount in the dp array.
    dp[amount] = minCoins == INT_MAX ? INT_MAX : minCoins;
    return dp[amount];
}

// Solution class that exposes the coin change function.
class Solution {
public:
    // Public method to find the minimum number of coins for a given amount.
    int coinChange(vector<int>& coins, int amount) {
        // Initialize the memoization array with -1, indicating that no amounts have been computed yet.
        vector<int> dp(amount + 1, -1);
        // Call the helper function to compute the minimum number of coins.
        int result = coinChangeRecursiveDP(coins, amount, dp);
        // If the result is INT_MAX, it means it's not possible to form the amount with the given coins, return -1.
        // Otherwise, return the result.
        return result == INT_MAX ? -1 : result;
    }
};
