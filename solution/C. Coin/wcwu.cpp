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
const int INF=INT_MAX; 
const ll N=2e6+5; 
ll dp[N]; 
bool ok[N]; 
signed main() { 
    IOS 
    rep(i, N) dp[i]=1e9+5; 
    ll n, p; 
    cin>>n>>p; 
    vector<ll> a(n); 
    rep(i, n) cin>>a[i]; 
    ok[0]=1; 
    rep(i, n) { 
        for(ll j=a[i];j<=2e6+5;j++) { 
            ok[j]=ok[j]|ok[j-a[i]]; 
        } 
    } 
    //cout<<ok[20]<<"\n"; 
    ll ans=1e9+5, ret=-1; 
    dp[0]=0; 
    rep(i, n) { 
        for(int j=a[i];j<=2e6+5;j++) { 
           dp[j]=min(dp[j], dp[j-a[i]]+1); 
        } 
    } 
    /*rep1(i, 40) { 
        cout<<dp[i]<<" "; 
        if(i%10==0) cout<<"\n"; 
    }*/
    for(int i=p;i<=2*p;i++) { 
        if(ok[i]) { 
            if(ans>dp[i]+dp[i-p]) { 
                ans=dp[i]+dp[i-p]; 
                ret=i; 
            } 
        } 
    } 
    cout<<ret<<" "<<ans<<"\n"; 
} 