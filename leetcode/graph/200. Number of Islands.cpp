int vis[302][302];

void dfs(int i, int j, int n, int m, vector<vector<char>>& grid) {
    // Check bounds and if the cell is already visited or is water
    if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] == 1 || grid[i][j] == '0') return;

    vis[i][j] = 1;  // Mark the cell as visited

    // Explore the adjacent cells
    dfs(i + 1, j, n, m, grid);
    dfs(i - 1, j, n, m, grid);
    dfs(i, j + 1, n, m, grid);
    dfs(i, j - 1, n, m, grid);
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Only start DFS if the cell is land and not visited
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    dfs(i, j, n, m, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
