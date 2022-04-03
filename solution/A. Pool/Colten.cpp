#include <bits/stdc++.h> 
  
#define int long long 
  
#define f first 
  
#define s second 
  
using namespace std; 
  
signed main(void) 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
      
    int n,m,k; 
      
    cin >> n >> m >> k; 
      
    vector <string> a(4); 
      
    int index = 0; 
      
    if( n + m == 2 ) 
    { 
        cin >> a[0] >> a[1]; 
          
        while(k--) 
        { 
            int input; 
              
            cin >> input; 
              
            cout << a[(input-1)%2] << "\n"; 
        } 
    } 
    else if( n == 1 ) 
    { 
        cin >> a[0] >> a[1] >> a[3]; 
          
        a[2] = a[0]; 
          
        while(k--) 
        { 
            int input; 
          
            cin >> input; 
          
            cout << a[(input-1)%4] << "\n"; 
        } 
    } 
    else
    { 
        cin >> a[0] >> a[2] >> a[1]; 
          
        a[3] = a[1]; 
          
        while(k--) 
        { 
            int input; 
          
            cin >> input; 
          
            cout << a[(input-1)%4] << "\n"; 
        } 
    } 
      
}