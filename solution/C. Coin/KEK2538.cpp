#include <bits/stdc++.h> 
using namespace std; 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define all(x) (x).begin(),(x).end() 
#define I_am_WEAK signed main() 
#define pii pair<int,int> 
#define pll pair<ll,ll> 
#define int long long 
  
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
const int N=2e6; 
bitset<N> dpok; 
int dp[N]; 
void solve(){    
    int n,p; cin>>n>>p; 
    vector<int>notes(n+1); 
    for(int i=1;i<=n;i++) cin>>notes[i]; 
    dpok[0]=1; 
    for(int i=1;i<=n;i++){ 
        for(int j=notes[i];j<=2e6+6;j++){ 
            dpok[j]=dpok[j]|dpok[j-notes[i]];          
        } 
    } 
    memset(dp,0x3f3f3f3f,sizeof(dp)); 
    int oo=dp[0]; 
    dp[0]=0; 
    for(int i=1;i<=n;i++){ 
        for(int j=notes[i];j<=2e6+6;j++){ 
           dp[j]=min(dp[j],dp[j-notes[i]]+1); 
        } 
    } 
    // for(int i=1;i<=40;i++){ 
    //     debug(i,dp[i]); 
    // } 
    int det=-1,ans=oo; 
    for(int i=p;i<=2*p;i++){ //give 
        if(dpok[i]&&dpok[i-p]){ 
            if(ans>dp[i]+dp[i-p]){ 
                ans=dp[i]+dp[i-p]; 
                det=i; 
            }  
        } 
    } 
    cout<<det<<' '<<ans<<'\n'; 
} 
  
I_am_WEAK{ IOS; 
    int t; t=1; 
    while(t--) solve(); 
} 