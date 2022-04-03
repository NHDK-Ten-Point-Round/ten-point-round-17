#include <bits/stdc++.h> 
#define int long long 
#define double long double 
#define Nanase_Kurumi_aka_menhera_chan_is_mine ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define pb push_back 
#define ALL(i) i.begin(),i.end() 
#define gcd(i,j) __gcd(i,j) 
#define fi first 
#define se second 
//#define X first 
//#define Y second 
#define eps 0.00000001 
#define ist insert 
#define DNE nullptr 
#pragma GCC optimize("Ofast") 
//#pragma GCC optimize("unroll-loops,no-stack-protector,fast-math") 
//#pragma GCC optimize("O2") 
int max(int x,int y){return x>=y?x:y;} 
int min(int x,int y){return x>=y?y:x;} 
using namespace std; 
typedef long long ll; 
typedef pair<double,double> pdd; 
typedef pair<ll, ll> pii; 
const int N=1000005; 
const int M=20000005; 
const int MOD=998244353;//1000000007; 
const ll INF=17000000000000000;//2147483647; 
// typedef pair<pdd,pdd> Line; 
  
struct SEG{ 
    int n; 
    vector<pii> node; 
    vector<int> sum; 
    void init(int _n){ 
        n=_n; 
        node.resize(4*n); 
        sum.resize(4*n); 
    } 
    void build(vector<int> &t,int pos,int l,int r){ 
        if (r-l==1){ 
            node[pos]={t[l],l}; 
            sum[pos]=t[l]; 
            return; 
        } 
        int m=(l+r)>>1; 
        build(t,2*pos+1,l,m); 
        build(t,2*pos+2,m,r); 
        node[pos]=min(node[2*pos+1],node[2*pos+2]); 
        sum[pos]=sum[2*pos+1]+sum[2*pos+2]; 
    } 
    void build(vector<int> &t){build(t,0,0,n);} 
  
    void modify(int i,int v,int pos,int l,int r){ 
        if (r-l==1){ 
            node[pos].fi+=v; 
            sum[pos]+=v; 
            return; 
        } 
        int m=(l+r)>>1; 
        if (i<m) modify(i,v,2*pos+1,l,m); 
        else modify(i,v,2*pos+2,m,r); 
        node[pos]=min(node[2*pos+1],node[2*pos+2]); 
        sum[pos]=sum[2*pos+1]+sum[2*pos+2]; 
    } 
    void modify(int i,int v){modify(i,v,0,0,n);} 
  
    pii query(int pos,int l,int r,int lq,int rq){ 
        if (l>=rq||r<=lq) return {INF,-1}; 
        if (lq<=l&&r<=rq) return node[pos]; 
        int m=(l+r)>>1; 
        return min(query(2*pos+1,l,m,lq,rq),query(2*pos+2,m,r,lq,rq)); 
    } 
    pii query(int lq,int rq){return query(0,0,n,lq,rq);} 
  
    int query_(int pos,int l,int r,int lq,int rq){ 
        if (l>=rq||r<=lq) return 0; 
        if (lq<=l&&r<=rq) return sum[pos]; 
        int m=(l+r)>>1; 
        return query_(2*pos+1,l,m,lq,rq)+query_(2*pos+2,m,r,lq,rq); 
    } 
    int query_(int lq,int rq){return query_(0,0,n,lq,rq);} 
} tr; 
void sol(){ 
    int n,q,k; 
    cin >>n>>q>>k; 
    vector<int> y(n); 
    for (int &i:y) cin >>i; 
    tr.init(n); 
    tr.build(y); 
    for (int i=0,l;i<q;i++){ 
        cin >>l; 
        l--; 
        int ll=l,rr=n-1,res=-1,mn=-1; 
        while (rr>=ll){ 
            int m=(ll+rr)>>1; 
            pii tmp=tr.query(l,m+1); 
            if (sqrt(tmp.fi)>=(m-l+1)){ 
                res=m; 
                mn=tmp.se; 
                ll=m+1; 
            } 
            else rr=m-1; 
        } 
        cout <<res-l+1<<' '<<tr.query_(l,res+1)<<'\n'; 
        tr.modify(mn,k*(res-l+1)); 
    } 
} 
signed main(){ 
    Nanase_Kurumi_aka_menhera_chan_is_mine 
    int _=1; 
    //cin >>_; 
    while (_--) sol(); 
    return 0; 
} 