// Define the maximum size of the graph based on the problem constraints
const int N = 2000 + 10; // Since 1 <= n <= 2000
// Declare global arrays to keep track of visited nodes and their colors
bool vis[N], col[N];
// Global flag to indicate if the graph can be bipartitioned
bool ok = 1;

// Depth-first search function to determine if the graph is bipartite
void dfs(int u, vector<int> adj[]) {
    // If we've already determined the graph isn't bipartite, we can return early
    if (!ok) return; 

    // Mark the current node as visited
    vis[u] = true;
    // Visit all adjacent nodes
    for (int v : adj[u]) {
        // If the adjacent node hasn't been visited yet
        if (!vis[v]) {
            // Color it with the opposite color of the current node
            col[v] = !col[u];
            // Continue the DFS from the adjacent node
            dfs(v, adj);
        } else if (col[u] == col[v]) {
            // If the adjacent node is already visited and has the same color,
            // we can't bipartition the graph
            ok = false; 
            return;
        }
    }
}

// Solution class contains the method to check if bipartition is possible
class Solution {
public:
    // Function to check if a bipartition is possible given the dislikes
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // Adjacency list representation of the graph
        vector<int> adj[N]; 
        // Reset the bipartite check flag
        ok = true;

        // Construct the adjacency list from the given edge list of dislikes
        for (const auto& d : dislikes) {
            // Since the dislike is mutual, add an edge in both directions
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        // Reset the visited and color arrays for a new graph
        memset(vis, 0, sizeof(vis)); 
        memset(col, 0, sizeof(col)); 

        // Iterate over each node to start DFS if it hasn't been visited
        for (int i = 1; i <= n && ok; ++i) { 
            if (!vis[i]) {
                // Color the starting node with color 0
                col[i] = 0; 
                // Start DFS from this node
                dfs(i, adj);
            }
        }

        // If the graph is bipartite, ok will be true, otherwise false
        return ok;
    }
};
