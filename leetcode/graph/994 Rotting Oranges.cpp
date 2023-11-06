class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        
        int cnt = -1;
        int n  = g.size();
        int m = g[0].size();
        int fresh  = 0;

        queue<pair<int, int>> q;

        for(int i= 0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if( g[i][j]  == 2)
                {
                    q.push({i,j});
                }
                else if(g[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        int ans = -1;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                auto p  = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                if(x+1<n && g[x+1][y]  == 1)
                {
                    q.push({x+1,y});
                    g[x+1][y] = 2;
                    fresh--;
                }
                if(y+1<m && g[x][y+1]  == 1){
                    q.push({x,y+1});
                    g[x][y+1] = 2;
                    fresh--;
                }

                if(x-1>=0 && g[x-1][y]  == 1){
                    q.push({x-1,y});
                    g[x-1][y] = 2;
                    fresh--;
                }
                if(y-1>=0 && g[x][y-1]  == 1){
                    q.push({x,y-1});
                    g[x][y-1] = 2;
                    fresh--;
                }
            }
            ans++;

        }

        if(fresh>0)
            return -1;
        if(ans == -1)
            return 0;
        return ans;
        
    }
};