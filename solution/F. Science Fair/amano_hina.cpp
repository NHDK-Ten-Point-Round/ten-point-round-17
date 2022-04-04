#include<bits/stdc++.h> 
using namespace std; 
#define F first 
#define S second 
#define pb push_back 
#define int long long 
int n,m,ans,dp[105][105]; 
string s1,s2; 
signed main() 
{ 
    cin.tie(0); 
    ios_base::sync_with_stdio(0); 
    ans=-1; 
    cin>>n>>m; 
    cin>>s1>>s2; 
    for(int i=0;i<100;i++) 
    { 
        dp[i][0]=i; 
        dp[0][i]=i; 
    } 
    for(int i=0;i<n;i++) 
    { 
        for(int j=0;j<m;j++) 
        { 
            for(int k1=1;k1<=n-i;k1++) 
            { 
                for(int k2=1;k2<=m-j;k2++) 
                { 
                    if(s1[i+k1-1]==s2[j+k2-1]) dp[k1][k2]=dp[k1-1][k2-1]; 
                    else dp[k1][k2]=1+min(min(dp[k1-1][k2-1],dp[k1][k2-1]),dp[k1-1][k2]); 
                    if(k1==k2&&k1>=10&&dp[k1][k2]*10<=k1) ans=max(ans,k1); 
                } 
            } 
        } 
    } 
    cout<<ans; 
} 