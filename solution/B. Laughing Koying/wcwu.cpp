#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll; 
#define rep(i, n) for(ll i=0;i<n;i++) 
#define rep1(i, n) for(ll i=1;i<=n;i++) 
#define pb push_back 
  
signed main() { 
    ll n, k; 
    cin>>n>>k; 
    vector<ll> a(n), l(n); 
    rep(i, n) cin>>a[i]; 
    rep(i, n) cin>>l[i]; 
    vector<ll> ans; 
    ll cur=0; 
    rep(i, n) { 
        if(cur+l[i]>=k) cur+=l[i]; 
        if(cur>=a[i]) { 
            ans.pb(i+1); 
            cur=0; 
        } 
    } 
    cout<<ans.size()<<"\n"; 
    for(ll u:ans) cout<<u<<" "; 
} 