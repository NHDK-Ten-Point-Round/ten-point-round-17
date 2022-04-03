#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std; 
using namespace __gnu_pbds; 
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
gp_hash_table<int, int> table; 
// beware of undefined behavior 
  
const int N=105; 
void solve(){ 
    int n,m; cin>>n>>m; 
    string s,t; cin>>s>>t; 
    s=' '+s,t=' '+t; 
    int ans=-1; 
    double a=(m+n)/2.; 
    for(int i=1;i+10-1<=n;i++){ 
        for(int j=1;j+10-1<=m;j++){ 
            int dp[N][N]; memset(dp,0x3f3f3f3f,sizeof(dp)); 
            dp[1][0]=dp[0][1]=1; 
            dp[0][0]=0; 
            for(int k=i;k<=n;k++){ 
                for(int l=j;l<=m;l++){ 
                    dp[0][l-j+1]=dp[l-j+1][0]=l-j+1; 
                    if(s[k]!=t[l]){ 
                        dp[k-i+1][l-j+1]=min({dp[k-i][l-j+1],dp[k-i+1][l-j],dp[k-i][l-j]})+1; 
                    }else dp[k-i+1][l-j+1]=dp[k-i][l-j]; 
                } 
            } 
            for(int len=10;len<=min(n-i+1,m-j+1);len++){ 
                double val=dp[len][len]; 
                if(val*10<=len) ans=max(ans,len); 
            } 
        } 
    } 
    cout<<ans<<'\n'; 
} 
  
/* 
30 30 
112222211211211222222221211122 
122211112121222211121112121111 
*/
I_am_WEAK{ IOS; 
    int t; t=1; 
    while(t--) solve(); 
}