#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N = 1e5+9;
vector<int> gp[N];
bool vis[N]; 
int dis[N],par[N];
 
void slove() {
 
   int n,m; cin>>n>>m;
 
    while(m--){
        int u,v; cin>>u>>v;
         gp[u].push_back(v);
         gp[v].push_back(u);
    }
   memset(dis, - 1, sizeof dis);
   queue<int>q;
   q.push(1); vis[1] = true; dis[1] = 0;
   while(!q.empty()){
    int u = q.front();
    q.pop();
    for(auto v : gp[u]){
        if(!vis[v]){
            q.push(v);
            dis[v] = dis[u] + 1;
            par[v] = u;
            vis[v] = true;
        }
    }
   }
   if(dis[n] == -1){
    cout<<"IMPOSSIBLE\n";
    return;
   }
   vector<int>path;
 
   cout<<dis[n] + 1<<endl;
   int v = n;
   while(v != 1){
    path.push_back(v);
    v = par[v];
   }
   path.push_back(1);
   reverse(path.begin(), path.end());
   for(auto v : path){
    cout<<v<<' ';
   }
   cout<<"\n";
    }
int main() { ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 1; //cin>>t;
    //int x = 1;
    while(t--)
    { //cout<< "Case "<<x<<": "; x++;
        slove();
    }
       }