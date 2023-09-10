#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N = 1e5+9;
int n,m;
vector<int>gp[N];
bool vis[N];
int ar[N],par[N];
vector<int>ans;
bool cycle = false;
void dfs(int u, int p){
    vis[u] = true;
    par[u] = p;
    for(auto v: gp[u]){
        if(cycle) return;
        if(!vis[v]){
            if(cycle) return;
            dfs(v,u);
        }
        else if(v != p){
            cycle = true;
            ans.push_back(v);
            while(u != v){
                ans.push_back(u);
                u = par[u];
            }
            ans.push_back(v);
            return;
        }
    }
    
}
 
void slove() {
   cin>>n>>m;
   for(int i = 1; i <= m; i++){
    int a,b;cin>>a>>b;
    gp[a].push_back(b);
    gp[b].push_back(a);
   }
   for(int i = 1; i <= n; i++){
    if(cycle) break;
    if(!vis[i]) dfs(i,0);
   }
   if(ans.size() == 0) {
    cout<<"IMPOSSIBLE"<<endl;
    return;
}
   cout<<ans.size()<<endl;
   for(auto x : ans) cout<<x<<" ";
    cout<<endl;
   
    }
int main() { ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; //cin>>t;
    //int x = 1;
    while(t--)
    { //cout<< "Case "<<x<<": "; x++;
        slove();
    }
       }