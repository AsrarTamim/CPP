class Solution {
public:
    // Function to check if it's possible to finish all tasks given their dependencies.
    bool canFinish(int n, vector<vector<int>>& v) {
        // Create an adjacency list representation of the graph.
        vector<int> g[n]; // 'g' is an array of vectors to represent the graph.
        vector<int> ans;  // Stores the order in which tasks can be completed.
        queue<int> q;     // A queue for performing topological sorting.

        // Create an array to store the in-degrees of each task.
        vector<int> indeg(n + 1, 0);

        // Populate the graph and in-degrees based on the input dependencies 'v'.
        for (auto& x : v) {
            g[x[1]].push_back(x[0]); // Task x[1] depends on task x[0].
            indeg[x[0]]++;           // Increase the in-degree of task x[0].
        }

        // Enqueue tasks with in-degree 0 as starting points for topological sorting.
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        // Perform topological sorting using BFS.
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            ans.push_back(temp); // Add the task to the order of completion.

            // Update in-degrees of dependent tasks and enqueue them if in-degree becomes 0.
            for (auto u : g[temp]) {
                indeg[u]--;
                if (indeg[u] == 0) {
                    q.push(u);
                }
            }
        }

        // If the order contains all tasks (n), it means all tasks can be completed.
        if (ans.size() == n) {
            return true;
        } else {
            return false;
        }
    }
};
