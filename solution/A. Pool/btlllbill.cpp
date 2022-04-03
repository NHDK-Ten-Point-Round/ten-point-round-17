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
const int N=2005; 
const int M=20000005; 
const int MOD=998244353;//1000000007; 
const ll INF=17000000000000000;//2147483647; 
// typedef pair<pdd,pdd> Line; 
  
int n,m,q; 
string s[3]; 
vector<string> ord; 
void sol(){ 
    cin >>n>>m>>q; 
    assert(n>0);assert(m>0);assert((n+m)==2||(m+n)==3); 
    if (n==2){ 
        cin >>s[0]>>s[1]>>s[2]; 
        ord.pb(s[0]); 
        ord.pb(s[2]); 
        ord.pb(s[1]); 
        ord.pb(s[2]); 
    } 
    else if (m==2){ 
        cin >>s[0]>>s[1]>>s[2]; 
        ord.pb(s[0]); 
        ord.pb(s[1]); 
        ord.pb(s[0]); 
        ord.pb(s[2]); 
    } 
    else { 
        cin >>s[0]>>s[1]; 
        ord.pb(s[0]); 
        ord.pb(s[1]); 
    } 
    for (int i=0,t;i<q;i++){ 
        cin >>t; 
        assert(t>=1);assert(t<=1000000000); 
        cout <<ord[(t-1)%(ord.size())]<<'\n'; 
    } 
} 
signed main(){ 
    Nanase_Kurumi_aka_menhera_chan_is_mine 
    int _=1; 
    //cin >>_; 
    while (_--) sol(); 
    return 0; 
} 