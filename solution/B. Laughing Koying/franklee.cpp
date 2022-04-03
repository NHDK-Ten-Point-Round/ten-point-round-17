#include <bits/extc++.h> 
#include <bits/stdc++.h> 
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math") 
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native") 
#pragma comment(linker, "/stack:200000000") 
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) 
#define int long long 
#define double long double 
#define pb push_back 
#define sz(x) (int)(x).size() 
#define all(v) begin(v),end(v) 
#define debug(x) cerr<<#x<<" = "<<x<<'\n' 
#define LINE cout<<"\n-----------------\n" 
#define endl '\n' 
#define VI vector<int> 
#define F first 
#define S second 
#define MP(a,b) make_pair(a,b) 
#define rep(i,m,n) for(int i = m;i<=n;++i) 
#define res(i,m,n) for(int i = m;i>=n;--i) 
#define gcd(a,b) __gcd(a,b) 
#define lcm(a,b) a*b/gcd(a,b) 
#define Case() int _;cin>>_;for(int Case = 1;Case<=_;++Case) 
using namespace __gnu_cxx; 
using namespace __gnu_pbds; 
using namespace std; 
template <typename K, typename cmp = less<K>, typename T = pairing_heap_tag> using _heap = __gnu_pbds::priority_queue<K, cmp, T>; 
template <typename K, typename M = null_type> using _hash = gp_hash_table<K, M>; 
template <typename K, typename M = null_type, typename cmp = less<K>, typename T = rb_tree_tag> using _tree = tree<K, M, cmp, T, tree_order_statistics_node_update>; 
template <typename K, typename M = null_type, typename cmp = less_equal<K>, typename T = rb_tree_tag> using _multitree = tree<K, M, cmp, T, tree_order_statistics_node_update>; 
template <typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; } 
typedef pair<int,int> pii; 
const int N = 1e4+5,K = 15,mod = 1e9+7,inf = 1e18+7; 
const double pi = acos(-1),eps = 1e-7; 
signed main(){ 
    IOS; 
    int n,m; 
    cin>>n>>m; 
    VI a(n),b(n); 
    rep(i,0,n-1){ 
        cin>>a[i]; 
    } 
    rep(i,0,n-1){ 
        cin>>b[i]; 
    } 
    VI ans; 
    int sum = 0; 
    rep(i,0,n-1){ 
        if(m<=b[i]){ 
            sum+=b[i]; 
        } 
        if(a[i]<=sum){ 
            ans.pb(i+1); 
            sum = 0; 
        } 
    } 
    cout<<sz(ans)<<endl; 
    for(auto i:ans){ 
        cout<<i<<' '; 
    } 
    cout<<endl; 
} 