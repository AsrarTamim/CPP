#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N = 1e5+10, inf = 1e9 + 9;
vector<int>g[N];
bool vis[N],col[N],ok;


void dfs(int u){

   for(auto v : g[u]){
      if(!vis[v]){
         col[v] = col[u] ^ 1;
         vis[v] = 1;
         dfs(v);
      }
      else{
         if(col[u] == col[v]){
            ok = 0;
         }
      }
   }
}


void slove() { 
   
      int n,m; cin>>n>>m;
      while(m--){
         int u,v; cin>>u>>v;
         g[u].push_back(v);
         g[v].push_back(u);
      }
      ok = 1;
      for(int i = 1; i <= n; i++)
         if(!vis[i]) dfs(i);

      if(ok){
         for(int i = 1; i <= n; i++){
            if(col[i]){
               cout<<"1 ";
            }
            else{
               cout<<"2 ";
            }
         }
         cout<<endl;
      }
      else{
         cout<<"IMPOSSIBLE"<<endl;
      }
    }
int main() { ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; //cin>>t;
    int x = 1;
    while(t--)
    { //cout<< "Case "<<x<<":\n"; x++;
        slove();
    }
       }
