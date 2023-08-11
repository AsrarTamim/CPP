#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
 
const int SIZE = 1e6+10;
const int mod = 1e9+7;
ll n,sum; 
ll ar[101];
ll dp[SIZE];
 
ll call(ll sum){
   if(sum == 0 ) return 1;
 
   ll ans = 0;
   if(dp[sum] != -1) return dp[sum];
 
   for(int i = 0; i < n; i++){
      if(sum>=ar[i])
      ans += (call( sum - ar[i] ) % mod);
   ans %= mod;
}
   return dp[sum] = ans;
}
void slove() {
   cin>>n>>sum;
   for(int i = 0; i < n; i++) cin>>ar[i];
      
   memset(dp, -1, sizeof dp);
   cout<<call(sum);
   
 
    }
int main() { ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1; //cin>>t;
    //int x = 1;
    while(t--)
    { //cout<< "Case "<<x<<": "; x++;
        slove();
    }
       }