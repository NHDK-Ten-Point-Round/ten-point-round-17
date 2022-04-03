#include<bits/stdc++.h> 
using namespace std; 
  
#define diexuan ios_base::sync_with_stdio(0); cin.tie(0); 
  
string a,b,c; 
int main(){ 
    diexuan 
  
    //freopen("C:\\Users\\User\\Desktop\\workplace\\input.txt","r",stdin); 
    //freopen("C:\\Users\\User\\Desktop\\workplace\\output.txt","w",stdout); 
  
    long long int n,m,t; 
    cin >> n >> m >> t; 
  
    if(n+m==3){ 
        cin >> a >> b >> c; 
    }else{ 
        cin >> a >> b; 
    } 
  
    while(t--){ 
        long long int q; 
        cin >> q; 
  
        if(n+m==2){ 
            if(q%2==1){ 
                cout << a << "\n"; 
            }else{ 
                cout << b << "\n"; 
            } 
        }else{ 
            if(n==2){ 
                if(q%4==1){ 
                    cout << a << "\n"; 
                }else if(q%4==3){ 
                    cout << b << "\n"; 
                }else{ 
                    cout << c << "\n"; 
                } 
            }else{ 
                if(q%4==2){ 
                    cout << b << "\n"; 
                }else if(q%4==0){ 
                    cout << c << "\n"; 
                }else{ 
                    cout << a << "\n"; 
                } 
            } 
        } 
    } 
  
    return 0; 
}