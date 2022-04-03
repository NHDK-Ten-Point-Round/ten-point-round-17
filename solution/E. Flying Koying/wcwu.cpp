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
const ll N=5005; 
ll dp[N][N]; 
ll h[N]; 
//dp[i][k]=max(sum(dp[i-j][k-1]), j=1 to r)+h_(i-j) 
signed main() { 
    IOS 
    ll n, r, k; 
    cin>>n>>r>>k; 
    rep1(i, n) cin>>h[i]; 
    rep1(i, n) dp[i][0]=0; 
    ll ans=0; 
    rep1(i, k) { 
        /*rep1(j, n) { 
            if(j<=i) dp[j][i]=0; 
            else { 
                rep1(k, r) { 
                    if(j-k<=0) break; 
                    dp[j][i]=max(dp[j][i], dp[j-k][i-1]+h[j-k]); 
                } 
            } 
            ans=max(ans, dp[j][i]); 
        }*/
        deque<ll> dq; 
        dp[1][i]=0; 
        dq.pb(1); 
        for(ll j=2;j<=n;j++) { 
            while(!dq.empty() && dq.front()<j-r) dq.pop_front(); 
            dp[j][i]=dp[dq.front()][i-1]+h[dq.front()]; 
            while(!dq.empty() && dp[dq.back()][i-1]+h[dq.back()]<dp[j][i-1]+h[j]) dq.pop_back(); 
            dq.pb(j); 
        } 
        rep1(j, n) ans=max(ans, dp[j][i]); 
    } 
    /*rep1(i, k) { 
        rep1(j, n) cout<<dp[j][i]<<" "; 
        cout<<"\n"; 
    }*/
    cout<<ans<<"\n"; 
} 