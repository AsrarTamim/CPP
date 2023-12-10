class Solution {
    // Helper function to calculate the minimum cost of cutting segments between indices i and j
    int minCostHelp(int i, int j, vector<vector<int>> &dp, vector<int> &cuts) {
        // Base case: If the segment is empty or invalid, return 0
        if (i > j) return 0;
        
        // If the result for this segment is already calculated, return it
        if (dp[i][j] != -1) return dp[i][j];
        
        // Initialize minimum cost for the current segment
        int mini = INT_MAX;
        
        // Iterate through all possible cut positions within the segment
        for (int k = i; k <= j; k++) {
            // Calculate the cost of cutting at position k and recursively compute costs for left and right segments
            mini = min(mini, cuts[j + 1] - cuts[i - 1] + minCostHelp(i, k - 1, dp, cuts) + minCostHelp(k + 1, j, dp, cuts));
        }
        
        // Save the calculated minimum cost for future reference and return it
        return dp[i][j] = mini;
    }

public:
    // Main function to find the minimum cost of cutting a rod of length len at specified positions
    int minCost(int len, vector<int>& cuts) {
        // Add the starting and ending points of the rod to the cuts array
        cuts.push_back(0);
        cuts.push_back(len);
        
        // Sort the cut positions for ease of computation
        sort(cuts.begin(), cuts.end());
        
        // Get the total number of cut positions
        int n = cuts.size();
        
        // Initialize a memoization table to store computed results for subproblems
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        // Call the helper function to find the minimum cost for the entire rod
        return minCostHelp(1, n - 2, dp, cuts);
    }
};
