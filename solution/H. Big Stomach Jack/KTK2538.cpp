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
  
// #define BUG 
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
const int N=2e5+5; 
struct Node{ 
    int id=-1; 
    int l,r,i,sum; 
    double mn; 
}st[N<<2]; 
int ar[N],K; 
  
void pull(int i){ 
    if(st[ls(i)].mn<=st[rs(i)].mn){ 
        st[i].mn=st[ls(i)].mn; 
        st[i].id=st[ls(i)].id; 
    }else { 
        st[i].mn=st[rs(i)].mn; 
        st[i].id=st[rs(i)].id; 
    } 
    st[i].sum=st[ls(i)].sum+st[rs(i)].sum; 
} 
void build(int l,int r,int i){ 
    st[i].l=l,st[i].r=r; 
    if(l==r){ 
        st[i].id=l; 
        st[i].mn=sqrt(ar[l]); 
        st[i].sum=ar[l]; 
        return; 
    } 
    int m=(l+r)>>1; 
    build(l,m,ls(i)),build(m+1,r,rs(i)); 
    pull(i); 
} 
void add(int p,int v,int i){ 
    if(st[i].l==st[i].r){ 
        assert(p==st[i].l); 
        ar[p]+=K*v; 
        st[i].sum=ar[p]; 
        st[i].mn=sqrt(ar[p]); 
        return; 
    } 
    int m=(st[i].l+st[i].r)>>1; 
    if(p<=m) add(p,v,ls(i)); 
    else add(p,v,rs(i)); 
    pull(i); 
} 
pair<double,int> askmin(int l,int r,int i){ //sqrt min 
    if(st[i].l==l&&st[i].r==r){ 
        // debug(st[i].mn,st[i].id); 
        return {st[i].mn,st[i].id}; 
    } 
    int m=(st[i].l+st[i].r)>>1; 
    if(r<=m) return askmin(l,r,ls(i)); 
    else if(l>m) return askmin(l,r,rs(i));  
    else return min(askmin(l,m,ls(i)),askmin(m+1,r,rs(i))); 
} 
int asksum(int l,int r,int i){ 
    if(st[i].l==l&&st[i].r==r){ 
        return st[i].sum; 
    } 
    int m=(st[i].l+st[i].r)>>1; 
    if(r<=m) return asksum(l,r,ls(i)); 
    else if(l>m) return asksum(l,r,rs(i)); 
    else return asksum(l,m,ls(i))+asksum(m+1,r,rs(i)); 
} 
void solve(){ 
    int n,q; cin>>n>>q>>K; 
    for(int i=1;i<=n;i++){ 
        cin>>ar[i]; 
    } 
    build(1,n,0); 
    while(q--){ 
        int x; cin>>x; 
        int l=1,r=n-x+2; // length 
        auto ok=[&](const int M){ 
            if(askmin(x,x+M-1,0).F>=(double)M) return 1;         
            return 0; 
        }; 
        while(l<r){ 
            int m=(l+r)>>1; 
            if(!ok(m)) r=m; 
            else l=m+1; 
        } 
        int len=l-1; 
        int id=askmin(x,x+len-1,0).S; 
        debug(id,x,x+len-1); 
        cout<<len<<' '<<asksum(x,x+len-1,0)<<'\n'; 
        add(id,len,0); 
    } 
} 
I_am_WEAK{ IOS; 
    int t; t=1; 
    while(t--) solve(); 
} 