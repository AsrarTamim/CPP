#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 9, mod = 1e9 + 7;
int ways[N];
int n;
int count(int n) {
  if (n == 0) return 1;
  if(n < 0) return 0;
  if (ways[n] != -1) return ways[n];
  int ans = 0;
  for (int i = 1; i <= 6; i++) {
    ans += count(n - i);
    ans %= mod;
  }
  return ways[n] = ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(ways, -1, sizeof ways);
  cin>>n;
  cout << count(n) << '\n';
  return 0;
}