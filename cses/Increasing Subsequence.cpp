#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int inf = 1e9 + 9;

const int N = 2e5 + 9;
int n;
int a[N];
int dp[N];
struct ST {
  int t[4 * N];
  static const int inf = 1e9;
  ST() {
    memset(t, 0, sizeof t);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      t[n] = max(t[n],x);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    t[n] = max(t[l], t[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return -inf;
    if (b >= i && e <= j) return t[n];
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
}t;

void slove() { 
   
   cin>>n;
    set<int>s;
    for(int i = 1; i<= n; i++) {
        cin>>a[i];
        s.insert(a[i]);
    }
    int id = 0;
    map<int,int> mp;
    for(auto x : s){
        mp[x] = ++id;
    }
    for(int i = 1; i <= n; i++) a[i] = mp[a[i]];
    for(int i = 1; i <= n; i++){
        dp[i] = 1;
        if(a[i] > 1){
            int mx = t.query(1,1,N,1,a[i]-1);
            mx++;
            dp[i] = max(dp[i],mx); 
        }
        t.upd(1,1,N,a[i],dp[i]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans,dp[i]);
    cout<<ans<<endl;  
    }
int main() { ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; //cin>>t;
    int x = 1;
    while(t--)
    { //cout<< "Case "<<x<<":\n"; x++;
        slove();
    }
       }
