#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N = 1e5+10, inf = 1e9 + 9;

template<class T> inline int sz(T container) {return (int)container.size();}
 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v){os << "VECTOR-->";os << "[";for (int i = 0; i < v.size(); ++i) {os << v[i];if (i != v.size() - 1)os << ", ";}os << "]\n";return os;}
template <typename T>ostream& operator<<(ostream& os, const set<T>& v){os << "SET-->";os << "[";for (auto it : v) {os << it;if (it != *v.rbegin())os << ", ";}os << "]\n";return os;}
template <typename T, typename S>ostream& operator<<(ostream& os, const map<T, S>& v){os << "KEY" << " : " << "ELEMENT\n";for (auto it : v)os << it.first << " : " << it.second << "\n";return os;}
template <typename T, typename S>ostream& operator<<(ostream& os, const pair<T, S>& v){os << "(";os << v.first << ", " << v.second << ")";return os;}
 
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << " "; err(++it, args...); }


void slove() { 
   
      
    }
int main() { ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin>>t;
    int x = 1;
    while(t--)
    { //cout<< "Case "<<x<<":\n"; x++;
        slove();
    }
       }
