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
const ll INF=2e18; 
const int N=1e5+5; 
ll id; 
struct Node{ 
    ll sum, mn, mnid; 
    Node *lc, *rc; 
    Node() {sum=mnid=0; mn=INF; lc=rc=NULL;} 
    void pull() { 
        sum=lc->sum+rc->sum; 
        mn=min(lc->mn, rc->mn); 
        if(lc->mn<=rc->mn) mnid=lc->mnid; 
        else mnid=rc->mnid; 
    } 
}; 
ll y[N], n, q, k; 
Node* build(int L, int R) { 
    Node *node=new Node(); 
    int mid=(L+R)>>1; 
    if(L==R) { 
        node->sum=node->mn=y[L]; 
        node->mnid=L; 
        return node; 
    } 
    node->lc=build(L, mid); 
    node->rc=build(mid+1, R); 
    node->pull(); 
    return node; 
} 
void modify(Node *node, int L, int R, int id, ll x) { 
    if(L==id && L==R) { 
        node->sum+=x; 
        node->mn+=x; 
        return; 
    } 
    int mid=(L+R)>>1; 
    if(id<=mid) modify(node->lc, L, mid, id, x); 
    else modify(node->rc, mid+1, R, id, x); 
    node->pull(); 
    return; 
} 
ll querysum(Node *node, int L, int R, int ql, int qr) { 
    if(L>qr || R<ql) return 0; 
    if(ql<=L && R<=qr) return node->sum; 
    int mid=(L+R)>>1; 
    return querysum(node->lc, L, mid, ql, qr)+querysum(node->rc, mid+1, R, ql, qr); 
} 
pll querymn(Node *node, int L, int R, int ql, int qr) { 
    if(L>qr || R<ql) return {INF, INF}; 
    if(ql<=L && R<=qr) return {node->mn, node->mnid}; 
    int mid=(L+R)>>1; 
    pll left=querymn(node->lc, L, mid, ql, qr), right=querymn(node->rc, mid+1, R, ql, qr); 
    if(left.F<=right.F) return {left.F, left.S}; 
    else return {right.F, right.S}; 
} 
  
signed main() { 
    IOS 
    cin>>n>>q>>k; 
    rep1(i, n) cin>>y[i]; 
    Node *root=build(1, n); 
    while(q--) { 
        ll x; 
        cin>>x; 
        ll l=x, r=n; 
        while(l<r) { 
            ll mid=(l+r+1)>>1; 
            if(querymn(root, 1, n, x, mid).F<(mid-x+1)*(mid-x+1)) r=mid-1; 
            else l=mid; 
            //cout<<l<<" "<<r<<"\n"; 
        } 
        cout<<r-x+1<<" "<<querysum(root, 1, n, x, r)<<"\n"; 
        ll id=querymn(root, 1, n, x, r).S; 
        //cout<<id<<"\n"; 
        modify(root, 1, n, id, k*(r-x+1)); 
    } 
} 
//koying orzorzorz 
/* 
5 3 1 
15 10 3 7 9 
1 
3 
5 
*/