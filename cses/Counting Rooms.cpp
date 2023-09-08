#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int SIZE = 1005;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n,m;
 
char grid[SIZE][SIZE];
bool vis[SIZE][SIZE];
 
bool is_valid(int i , int j){
    return i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == 0 && grid[i][j] != '#';
 
}
 
void dfs(int i , int j){
    vis[i][j] = 1;
    for(int k = 0; k < 4; k++){
        int x = dx[k] + i,y = dy[k] + j;
        if(is_valid(x,y)) dfs(x,y);
    }
}
void slove() {
 
   cin>>n>>m;
   for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        cin>>grid[i][j];
 
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.' && is_valid(i,j)){
                dfs(i,j);
                cnt++;
            }
        }
    }
cout <<cnt<<endl;
 
    }
int main() { ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;// cin>>t;
    //int x = 1;
    while(t--)
    { //cout<< "Case "<<x<<": "; x++;
        slove();
    }
       }