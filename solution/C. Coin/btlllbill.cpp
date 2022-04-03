#include <bits/stdc++.h> 
//#define int long long 
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
  
int n,p; 
int a[25]; 
int dp[2*N]; 
void sol(){ 
    cin >>n>>p; 
    for (int i=1;i<=n;i++) 
        cin >>a[i]; 
    dp[0]=0; 
    for (int i=1;i<=2*p;i++){ 
        int k=2147483647; 
        for (int j=1;j<=n;j++) 
            if (a[j]<=i) 
                k=min(dp[i-a[j]],k); 
        dp[i]=k+1; 
    } 
    int cnt=2147483647,res=0; 
    for (int i=p;i<=2*p;i++){ 
        if (cnt>dp[i]+dp[i-p]){ 
            cnt=dp[i]+dp[i-p]; 
            res=i; 
        } 
  
    } 
    cout <<res<<' '<<cnt<<'\n'; 
} 
signed main(){ 
    Nanase_Kurumi_aka_menhera_chan_is_mine 
    int _=1; 
    //cin >>_; 
    while (_--) sol(); 
    return 0; 
} 