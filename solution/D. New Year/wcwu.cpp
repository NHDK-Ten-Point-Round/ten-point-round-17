#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll; 
typedef pair<ll, ll> pll; 
#define rep(i, n) for(ll i=0;i<n;i++) 
#define rep1(i, n) for(ll i=1;i<=n;i++) 
#define IOS ios::sync_with_stdio(false);cin.tie(0); 
#define pb push_back 
#define F first 
#define S second 
const ll N=2e5+5; 
vector<ll> G[N]; 
ll d[N], col1[N], col2[N]; 
ll n, m; 
bool vis[N]; 
vector<ll> cur; 
ll ans=n+1; 
void col1dfs(int st) { 
    cur.pb(st); 
    for(auto u:G[st]) { 
        if(col1[u]==-1) { 
            col1[u]=col1[st]^1; 
            col1dfs(u); 
        } 
    } 
} 
void col2dfs(int st) { 
    cur.pb(st); 
    for(auto u:G[st]) { 
        if(col2[u]==-1) { 
            col2[u]=col2[st]^1; 
            col2dfs(u); 
        } 
    } 
} 
bool check(int n) { 
    ll now=0; 
    rep1(i, n) { 
        ans=n+1; 
        if(col1[i]!=-1) continue; 
        cur.clear(); 
        if(col1[i]==-1) { 
            col1[i]=0; 
            col1dfs(i); 
            ll cnt=0; 
            for(auto v:cur) { 
                if(d[v]!=col1[v]) cnt++; 
                //cout<<d[v]<<" "<<col1[v]<<"\n"; 
                //cout<<cnt<<"\n"; 
            } 
            ans=min(ans, cnt); 
        } 
        /*rep1(i, n) cout<<col1[i]<<" "; 
        cout<<"\n"; 
        cout<<ans<<"\n";*/
        cur.clear(); 
        if(col2[i]==-1) { 
            col2[i]=1; 
            col2dfs(i); 
            ll cnt=0; 
            for(auto v:cur) if(d[v]!=col2[v]) cnt++; 
            ans=min(ans, cnt); 
        } 
        /*rep1(i, n) cout<<col2[i]<<" "; 
        cout<<"\n"; 
        cout<<ans<<"\n";*/
        if(ans!=n+1) now+=ans; 
        ans=1+n; 
    } 
    rep1(i, n) { 
        for(auto p:G[i]) { 
            if(col1[i]==col1[p]) return false; 
        } 
    } 
    ans=now; 
    return true; 
} 
signed main() { 
    IOS 
    cin>>n>>m; 
    rep1(i, n) { 
        vis[i]=0; 
        col1[i]=col2[i]=-1; 
        G[i].clear(); 
    } 
    rep1(i, n) cin>>d[i]; 
    rep(i, m) { 
        ll x, y; 
        cin>>x>>y; 
        G[x].pb(y); 
        G[y].pb(x); 
    } 
    if(!check(n)) { 
        cout<<"-1\n"; 
        return 0; 
    } 
    cout<<ans<<"\n"; 
} 