#include<bits/stdc++.h> 
using namespace std; 
typedef long long ll; 
signed main() { 
    int n, m, t; 
    cin>>n>>m>>t; 
    if(n+m==2) { 
        string a, b; 
        cin>>a>>b; 
        while(t--) { 
            ll q; 
            cin>>q; 
            if(q&1) cout<<a<<"\n"; 
            else cout<<b<<"\n"; 
        } 
    } 
    else { 
        string a, b, c; 
        cin>>a>>b>>c; 
        if(n==1) { 
            while(t--) { 
                ll q; 
                cin>>q; 
                if(q&1) cout<<a<<"\n"; 
                else if(q%4==2) cout<<b<<"\n"; 
                else cout<<c<<"\n"; 
            } 
        } 
        else { 
  
            while(t--) { 
                ll q; 
                cin>>q; 
                if(q%2==0) cout<<c<<"\n"; 
                else if(q%4==1) cout<<a<<"\n"; 
                else cout<<b<<"\n"; 
            } 
        } 
    } 
} 