

// you can use dp size N*X
// in that case optimize the size we need just previus row ans for the current ans so we just need 2 rows



#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N = 105, X = 1e6+5, inf = 1e9 + 9;
int n,x;
int c[N];
int dp[2][X];

void slove() { 
   
      cin>>n>>x;
      for(int i = 1; i <= n; i++) cin>>c[i];
      for(int sum = 1; sum <= x; sum++) dp[0][sum] = inf;
         dp[0][0] = 0;
      for(int i = 1; i <= n; i++){
         for(int sum = 0; sum <= x; sum++){
            dp[1][sum] = dp[0][sum];
            if(sum >= c[i]) dp[1][sum] = min(dp[1][sum],dp[1][sum-c[i]]+1);
         }
         for(int sum = 0; sum <= x; sum++){
            dp[0][sum] = dp[1][sum];
         }
      }
      cout<<(dp[1][x] >= inf ? -1 : dp[1][x])<<endl;
    }
int main() { ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; 
    int x = 1;
    while(t--)
    { 
        slove();
    }
       }
