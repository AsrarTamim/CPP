#include<bits/stdc++.h>
using namespace std;
 
 
const int N = 1e5 + 9;
vector<int>gp[N];
int col[N], par[N];
bool found;
vector<int>cycle;
int n,m;
 
void dfs(int u) {
   if(found) return;
   col[u] = 1;   
 
   for (auto v: gp[u]) {
      if(found) return;
      if (col[v] == 0) {
         par[v] = u;
         dfs(v);
    }
      else if (col[v] == 1) {
      found = true;
      int st = u;
      while (u != v) {
        cycle.push_back(u);
        u = par[u];
      }
      cycle.push_back(v);
      cycle.push_back(st);
      reverse(cycle.begin(), cycle.end());
      return;
    }
  }
  col[u] = 2;
}
 
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  cin>>n>>m;
   for(int i = 1; i <= m; i++){
    int a,b;cin>>a>>b;
    gp[a].push_back(b);
   }
 
   found = false;
   for (int i = 1; i <= n; i++) {
   if (col[i] == 0) dfs(i);
   if(found) break;
  }
 
   if(cycle.size() == 0) {
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
 
   cout<<cycle.size()<<endl;
   for(auto x : cycle) cout<<x<<" ";
    cout<<endl;
 
  return 0;
}