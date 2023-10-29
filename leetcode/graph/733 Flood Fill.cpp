
void dfs(vector<vector<int>>& g, int i,int j,int color,int x){
    int n = g.size();
    int m = g[0].size();
    if(i < 0 || j < 0) return;
    if(i >= n || j >= m) return;
    if(g[i][j] != x) return;
    g[i][j] = color;
    dfs(g,i+1,j,color,x);
    dfs(g,i,j+1,color,x);
    dfs(g,i-1,j,color,x);
    dfs(g,i,j-1,color,x);
}



class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image[0].size();
        int x = image[sr][sc];
        if(x != color)
        dfs(image,sr,sc,color,x);
        return image;
    }
};