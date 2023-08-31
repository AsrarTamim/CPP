#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N = 1e5+10, inf = 1e9 + 9;

int n;
int ar[105];
set<int>s;
int dp[105][N];

int f(int i , int sum){
   if(i == n+1) return 0;
   int &ans = dp[i][sum];
   if(ans != -1) return ans;
   ans = 0;
   ans = f(i+1,sum + ar[i]);
   if(sum+ar[i])
   s.insert(sum+ar[i]);
   ans = f(i+1,sum);
   return ans;
}


void slove() { 
   
   cin>>n;
   for(int i = 1; i <= n; i++) cin>>ar[i];
   memset(dp,-1,sizeof dp);
   f(1,0);
   cout<<s.size()<<endl;
   for(auto x : s) cout<<x<<" ";
   cout<<endl;
      
    }
int main() { ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; //cin>>t;
    int x = 1;
    while(t--)
    { //cout<< "Case "<<x<<":\n"; x++;
        slove();
    }
       }
