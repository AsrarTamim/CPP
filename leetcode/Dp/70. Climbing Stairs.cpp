// Define a global array for dynamic programming
int dp[50];

// Recursive function to calculate the number of ways to climb stairs
int fun(int n) {
    // Base case: If there are no stairs remaining, there is one way to climb (no further steps needed)
    if (n == 0) {
        return 1;
    }
    
    // Base case: If the number of stairs is negative, it is not possible to climb, return 0 ways
    if (n < 0) {
        return 0;
    }

    // Memoization: Check if the result is already computed
    int &ans = dp[n];
    if (ans != -1) return ans;

    // Initialize the answer variable
    ans = 0;

    // Recursively calculate the number of ways to climb by taking either 1 or 2 steps
    ans += fun(n - 1);
    ans += fun(n - 2);

    // Memoize the computed result
    dp[n] = ans;
    
    // Return the result
    return dp[n];
}

// Class definition for the Solution
class Solution {
public:
    // Function to calculate the number of ways to climb stairs using dynamic programming
    int climbStairs(int n) {
        // Initialize the dp array with -1
        memset(dp, -1, sizeof dp);
        
        // Call the recursive function to calculate the result
        return fun(n);
    }
};
