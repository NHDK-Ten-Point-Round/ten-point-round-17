#include <bits/stdc++.h> 
using namespace std; 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define all(x) (x).begin(),(x).end() 
#define ls(x) (x*2+1) 
#define rs(x) (x*2+2) 
#define lowbit(x) (x & -x) 
#define I_am_WEAK signed main() 
#define pii pair<int,int> 
#define pll pair<ll,ll> 
#define int long long 
#define F first 
#define S second 
#define sz(x) ((int)(x).size()) 
  
#define BUG 
#ifdef BUG 
void _debug() {cerr << "\033[0m\n";} 
template <typename A, typename... B> 
void _debug(A a, B... b) {cerr << a << ' ', _debug(b...);} 
#define debug(args...) cerr << "\033[1;32m(" << (#args) << ") : ", _debug(args);  
#else 
#pragma GCC optimize("Ofast") 
#pragma GCC optimize ("unroll-loops") 
#define debug(...) ((void)0) 
#endif 
const int oo = 2000000000; // 2e9 
const int N=1e5+5; 
void solve(){    
    int n,k; cin>>n>>k; 
    vector<int> ar(n+1),br(n+1); 
    for(int i=1;i<=n;i++){ 
        cin>>ar[i]; 
    } 
    for(int i=1;i<=n;i++){ 
        cin>>br[i]; 
    } 
    int sum=0; 
    vector<int> days; 
    for(int i=1;i<=n;i++){ 
        if(br[i]>=k){ 
            sum+=br[i]; 
        } 
        if(sum>=ar[i]){ 
            days.push_back(i); 
            sum=0; 
        } 
    } 
  
    cout<<sz(days)<<'\n'; 
    for(auto d:days) cout<<d<<' '; 
} 
  
I_am_WEAK{ IOS; 
    int t; t=1; 
    while(t--) solve(); 
} 