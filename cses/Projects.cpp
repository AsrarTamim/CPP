#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N = 2e5+10, inf = 1e9 + 9;

int n;
ll dp[N],pre[N];
struct node
{
   int l,r,p;
}a[N];

bool cmp(node x,node y){
   return  x.r < y.r;
}

void slove() { 
      
   cin>>n;

   for(int i =1; i <= n;i++) cin>>a[i].l>>a[i].r>>a[i].p;

   sort(a+1,a+n+1,cmp);

   for(int i = 1; i <= n; i++){

      dp[i] = a[i].p;
      ll mx = 0;
      int j =0;
      int L= 1,R= i-1;
      while(L <= R){
         int mid = (L + R) >> 1;

         if(a[i].l > a[mid].r){
            L = mid+1;
            j = mid;
         }
         else {
            R = mid - 1;
         }

      }
      mx = pre[j] + a[i].p;
      dp[i] = max(mx,dp[i]);
      pre[i] = max(pre[i-1],dp[i]);
   }
   ll ans=0;
   for(int i = 1; i <= n; i++){
      ans = max(ans,dp[i]);
   }
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
