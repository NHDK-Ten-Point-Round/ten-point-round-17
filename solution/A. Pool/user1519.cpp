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
  
ll n, m, t, q; 
string a[2], b[2], ans[4]; 
  
void solve() { 
  
    if (n+m == 3) { 
        if (n == 2) { 
            ans[0] = a[0]; 
            ans[2] = a[1]; 
            ans[1] = ans[3] = b[0]; 
        } else { 
            ans[1] = b[0]; 
            ans[3] = b[1]; 
            ans[0] = ans[2] = a[0]; 
        } 
    } else { 
        ans[0] = ans[2] = a[0]; 
        ans[1] = ans[3] = b[0]; 
    } 
  
    return ; 
  
} 
  
void go() { 
  
    cin >> n >> m >> t; 
    For (i, 0, n) cin >> a[i]; 
    For (i, 0, m) cin >> b[i]; 
  
    solve(); 
  
    while (t--) { 
        cin >> q; 
        cout << ans[--q%4] << endl; 
    } 
  
    return ; 
  
} 
  
int main() { 
      
    FAST; 
  
    go(); 
  
    return 0; 
  
}