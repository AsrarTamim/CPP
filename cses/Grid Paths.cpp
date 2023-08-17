#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const int N = 1005, inf = 1e9 + 9,mod = 1e9+7;
int n;
int dp[N][N];
string s[N];
int f(int i, int j){  
    if(i >= n or j >= n) return 0;
    if(s[i][j] == '*') return 0;
    if(i == n - 1 and j == n-1) return 1;
    
    int &ans = dp[i][j];
    if(ans != -1) return ans; 
    ans = f(i,j+1);
    ans += f(i+1,j);
    ans %= mod;
    return ans;
}
void slove() { 
   

    cin>>n;
    
    for(int i = 0; i < n; i++){
        cin>>s[i];
    }
    memset(dp, -1, sizeof dp);
    cout<<f(0,0)<<endl;

    }
int main() { ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; //cin>>t;
    int x = 1;
    while(t--)
    { //cout<< "Case "<<x<<":\n"; x++;
        slove();
    }
       }
