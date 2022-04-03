#include <bits/stdc++.h> 
using namespace std; 
  
// #define DEBUG 
#ifdef DEBUG 
    #define FAST freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout) 
#else 
    #define FAST ios::sync_with_stdio(0), cin.tie(0); 
    #define endl '\n' 
#endif 
  
using ll = long long; 
using db = double; 
#define F first  
#define S second 
#define pii pair<ll,ll>  
#define eb emplace_back 
#define void inline void 
#define tcase ll t; cin >> t; while (t--) 
#define For(a, b, c) for (ll a = b; a < c; a++) 
#define Forr(a, b, c) for (ll a = b; a >= c; a--) 
#define lowbit(x) (x & -x) 
#define _ << ' ' <<  
const ll maxn = 1e5+5; 
const ll mod = 998244353; 
  
ll n, k; 
ll a[maxn], l, now; 
vector<ll> v; 
  
void solve(ll i) { 
  
    if (l >= k) now += l; 
      
    if (now >= a[i]) { 
        v.eb(i+1); 
        now = 0; 
    } 
  
    return ; 
  
} 
  
void go() { 
  
    cin >> n >> k; 
    For (i, 0, n) cin >> a[i]; 
    For (i, 0, n) { 
        cin >> l; 
        solve(i); 
    } 
  
    cout << v.size() << endl; 
    for (auto &i:v) cout << i << ' '; 
  
    return ; 
  
} 
  
int main() { 
      
    FAST; 
  
    go(); 
  
    return 0; 
  
}