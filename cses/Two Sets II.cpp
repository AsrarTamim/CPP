#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N = 1e5+10, mod = 1e9 + 7;

int n,sum;
int dp[505][N];

int f(int i,int res){
   if(res == sum) return 1;
   if(res > sum) return 0;
   if(i > n) return 0;
   int &ans = dp[i][res];
   if(ans != -1) return ans;
   ans = 0;
   ans += f(i+1, res + i);
   ans %= mod;
   ans += f(i+1,res);
   ans %= mod;

   return ans;
}
int power(int a, int k){
   int ans = 1;
   while(k){
      if(k & 1){
         ans = 1LL* ans * a %mod;
      }
      a = 1LL * a* a % mod;
      k >>=1;
   }
   return ans;
}
int inv(int x){
   return power(x,mod-2);
}

void slove() { 
   
   cin>>n;

   sum = (n * (n+1))/2;
   if(sum % 2){
      cout<<"0"<<endl; return;
   }
   sum/=2;
   memset(dp,-1,sizeof dp);

   cout<<1LL * f(1,0) * inv(2) % mod<<endl;
 
      
    }
int main() { ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; //cin>>t;
    int x = 1;
    while(t--)
    { 
        slove();
    }
       }
