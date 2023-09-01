#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int n;
ll ar[5005],dp[5005][5005][2];
bool vis[5005][5005][2];


ll f(int i, int j, int who){
   if(i > j) return 0;

   ll &ans = dp[i][j][who];
   if(vis[i][j][who]) return ans;
   if(who){
      ll ans1 = f(i+1,j,0) + ar[i];
      ll ans2 = f(i,j-1,0)+ ar[j];
      ans = max(ans1,ans2);
   }
   else{
      ll ans1 = f(i+1,j,1);
      ll ans2 = f(i,j-1,1);
      ans = min(ans1,ans2);
   }
   vis[i][j][who] = true;
   return ans;
}

void slove() { 
   
   cin>>n;
   for(int i = 1; i <= n; i++) cin>>ar[i];
   memset(dp,-1,sizeof dp);
   memset(vis,0,sizeof vis);
   cout<<f(1,n,1);
      
    }
int main() { ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; //cin>>t;
    int x = 1;
    while(t--)
    { //cout<< "Case "<<x<<":\n"; x++;
        slove();
    }
       }
