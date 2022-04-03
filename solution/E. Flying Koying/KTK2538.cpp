#include <bits/stdc++.h> 
using namespace std; 
#define pii pair<int,int> 
#define F first 
#define S second 
#define int long long 
#define sz(x) ((int)x.size()) 
  
const int N=5e3+3; 
int ar[N],dp[N][N]; 
/* 
dp[times][choosing this index] 
*/
signed main(){ 
    int n,r,k; cin>>n>>r>>k; 
    vector<pii> stk1,stk2;  
    for(int i=1;i<=n;i++){ 
        stk1.push_back({i,0}); 
    } 
    for(int i=1;i<=n;i++) cin>>ar[i]; 
    for(int i=0;i<k;i++){ 
        deque<pii> tmp; 
        tmp.push_back({0,0}); // {pos,value} 
        for(int j=1;j<n;j++){ 
            while(sz(tmp)&&tmp.front().F<j-r){ 
                tmp.pop_front(); 
            } 
            dp[i+1][j]=tmp.front().S+ar[j]; 
            while(sz(tmp)&&tmp.back().S<=stk1[j-1].S){ 
                tmp.pop_back(); 
            } 
            tmp.push_back({j,stk1[j-1].S});     
            stk2.push_back({j,dp[i+1][j]}); 
        } 
        stk1=vector<pii>(); 
        stk1.swap(stk2); 
    } 
  
    int mx=0; 
    for(int i=1;i<=n;i++){ 
        mx=max(mx,dp[k][i]); 
    } 
    cout<<mx<<'\n'; 
} 