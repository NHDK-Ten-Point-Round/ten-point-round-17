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
  
  
void solve(){    
    int n,m,t; cin>>n>>m>>t; 
    string str[n+m]; 
    for(int i=0;i<n+m;i++){ 
        cin>>str[i]; 
    } 
    while(t--){ 
        int x; cin>>x; 
        if(x&1){ 
            if(n==1){ 
                cout<<str[0]<<'\n'; 
            }else{ 
                if((x/2)&1) cout<<str[1]<<'\n'; 
                else cout<<str[0]<<'\n'; 
            } 
        }else{ 
            if(m==1){ 
                if(n==1) cout<<str[1]<<'\n'; 
                else cout<<str[2]<<'\n'; 
            }else{  
                if((x/2)&1) cout<<str[1]<<'\n'; 
                else cout<<str[2]<<'\n'; 
            } 
        } 
    } 
} 
I_am_WEAK{ IOS; 
    int t; t=1; 
    while(t--) solve(); 
} 