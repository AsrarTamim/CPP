#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N = 1e5+10, inf = 1e9 + 9;
string a,b;
int n,m; 
int dp[5005][5005];
int f(int i , int j){
    if(i == n){
        if(j == m) return 0;
        return m-j;
    }
    if(j == m) return n - i;
    int &ans = dp[i][j];
    if(ans != -1 ) return ans;
    ans = inf;
    if(a[i] == b[j]) ans = min(ans,f(i+1,j+1));
 
    ans = min(ans,1+f(i+1,j+1));
    ans = min(ans,1+f(i+1,j));
    ans = min(ans,1+f(i,j+1));
 
    return ans;
 
}
void slove() { 
   
    cin>>a>>b;
    n = a.size(); m = b.size();
    memset(dp,-1, sizeof dp);
    cout<<f(0,0)<<'\n';
      
    }
int main() { ios_base::sync_with_stdio(0);cin.tie(0);
 
    int t = 1;// cin>>t;
    int x = 1;
    while(t--)
    { //cout<< "Case "<<x<<":\n"; x++;
        slove();
    }
       }