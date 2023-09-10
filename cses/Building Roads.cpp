#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N = 2e5+10;
int n,m;
vector<int>gp[N];
bool vis[N];
 
void dfs(int u){
    vis[u] = true;
    for(auto v : gp[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
 
void slove() {
 
   cin>>n>>m;
 
   while(m--){
    int a,b; cin>>a>>b;
    gp[a].push_back(b);
    gp[b].push_back(a);
   }
   int cnt_gp = 0;
   vector<int> ans;
   for(int i = 1; i <= n; i++){
        if(!vis[i]){
            ans.push_back(i);
            dfs(i);
            cnt_gp++;
        }
   }
   cout<<cnt_gp - 1<<endl;
   for(int i = 1; i < ans.size(); i++){
    cout<<ans[0]<<' '<<ans[i]<<endl;
   }
   
    }
int main() { ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; //cin>>t;
    //int x = 1;
    while(t--)
    { //cout<< "Case "<<x<<": "; x++;
        slove();
    }
       }