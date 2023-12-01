class Solution {
public:
    int dp[60001]; // Memoization array to store computed results for dynamic programming

    int solve(int idx, vector<vector<int>>& vec, vector<int>& st) {
        if (idx >= vec.size()) // Base case: If the index exceeds the size of the vector 'vec'
            return 0;
        
        if (dp[idx] != -1) // If the result for the current index is already computed, return it
            return dp[idx];

        // Find the index of the next element whose start time is greater than or equal to the current job's end time
        int nextEle = lower_bound(st.begin(), st.end(), vec[idx][1]) - st.begin();

        // Calculate the profit if the current job is taken
        int take = vec[idx][2] + solve(nextEle, vec, st);

        // Calculate the profit if the current job is not taken
        int notTake = solve(idx + 1, vec, st);

        // Return the maximum of taking and not taking the current job, and store it in dp array
        return dp[idx] = max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(dp, -1, sizeof(dp)); // Initialize the memoization array with -1
        int n = startTime.size();
        vector<vector<int>> vec(n);

        // Create a 2D vector 'vec' to store start time, end time, and profit for each job
        for (int i = 0; i < n; i++) {
            vec[i] = {startTime[i], endTime[i], profit[i]};
        }

        // Sort the 'vec' vector based on start times to ensure jobs are considered in chronological order
        sort(vec.begin(), vec.end());

        // Sort the 'startTime' vector for later use in finding the next element index efficiently
        sort(startTime.begin(), startTime.end());

        // Call the recursive solve function with initial parameters
        return solve(0, vec, startTime);
    }
};
