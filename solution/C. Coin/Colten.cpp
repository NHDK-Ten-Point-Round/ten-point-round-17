#include <bits/stdc++.h> 
  
#define int long long 
  
using namespace std; 
  
signed main(void) 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
      
    int n,m; 
      
    cin >> n >> m; 
      
    vector <int> a(n),dp1(2*m+1,1e18),dp2(2*m+1,1e18); 
      
    for(int i=0;i<n;i++) cin >> a[i]; 
      
    dp1[0] = 0; 
      
    for(int i=1;i<=2*m;i++) 
    { 
        for(int k=0;k<n;k++) 
        { 
            if( a[k] > i ) continue; 
              
            dp1[i] = min(dp1[i],dp1[i-a[k]]+1); 
        } 
    } 
      
    dp2[0] = 0; 
      
    for(int i=0;i<n;i++) 
    { 
        for(int k=a[i];k<=m;k++) 
        { 
            dp2[k] = min(dp2[k],dp2[k-a[i]]+1); 
        } 
    } 
      
    int ans = 1e18 , s = 1e18; 
      
    for(int i=m;i<=2*m;i++) 
    { 
        if( dp1[i] != 1e18 ) 
        {    
            if( dp1[i] != 1e18 && dp2[i-m] != 1e18 && dp1[i] + dp2[i-m] < ans ) 
            { 
                ans = dp1[i] + dp2[i-m]; 
                  
                s = i; 
            } 
        } 
    } 
      
    //cout << dp1[975888] + dp2[975888-m] << "\n"; 
      
    cout << s << " " << ans << "\n";  
}