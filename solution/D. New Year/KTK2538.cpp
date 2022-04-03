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
const int N=5e3+3; 
int ori[N],c[N]; 
vector<int> g[N],nodes; 
void dfs(int x,int p){ 
    c[x]=c[p]^1; 
    nodes.push_back(x); 
    for(auto u:g[x]){ 
        if(c[u]==-1){ 
            dfs(u,x); 
        }else{ 
            if(c[u]==c[x]){ 
                cout<<-1<<'\n'; 
                exit(0); 
            } 
        } 
    } 
} 
void solve(){    
    int n,m; cin>>n>>m; 
    for(int i=1;i<=n;i++){ 
        cin>>ori[i]; 
    }    
    for(int i=0;i<m;i++){ 
        int a,b; cin>>a>>b; 
        g[a].push_back(b); 
        g[b].push_back(a); 
    } 
    int ans=0; 
    memset(c,-1,sizeof(c)); 
    for(int i=1;i<=n;i++){ 
        if(c[i]==-1){ 
            int A=0,B=0; 
            c[i]=1; 
            nodes.clear(); 
  
            dfs(i,i); 
            for(auto j:nodes){ 
                // debug(i,j); 
                if(c[j]!=ori[j]) A++; 
                c[j]^=1; 
            } 
            for(auto j:nodes){ 
                if(c[j]!=ori[j]) B++; 
            } 
            ans+=min(A,B); 
        }    
    } 
    cout<<ans<<'\n'; 
} 
  
I_am_WEAK{ IOS; 
    int t; t=1; 
    while(t--) solve(); 
}