#include<bits/stdc++.h> 
using namespace std; 
int main(){ 
  int a,b;cin>>a>>b; 
  int q;cin>>q; 
  if(a==1&&b==1){ 
    string c,d; 
    cin>>c>>d; 
    for(int i=0;i<q;i++){ 
      int k;cin>>k; 
      if(k%2==1){ 
        cout<<c<<endl; 
      } 
      else{ 
        cout<<d<<endl; 
      } 
    } 
  } 
  else if(a==1&&b==2){ 
    string c,d,e; 
    cin>>c>>d>>e; 
    for(int i=0;i<q;i++){ 
      int k;cin>>k; 
      if(k%4==1){ 
        cout<<c<<endl; 
      } 
      if(k%4==2){ 
        cout<<d<<endl; 
      } 
      if(k%4==3){ 
        cout<<c<<endl; 
      } 
      if(k%4==0){ 
        cout<<e<<endl; 
      } 
    } 
  } 
  else if(a==2&&b==1){ 
    string c,d,e; 
    cin>>c>>d>>e; 
    for(int i=0;i<q;i++){ 
      int k;cin>>k; 
      if(k%4==1){ 
        cout<<c<<endl; 
      } 
      if(k%4==2){ 
        cout<<e<<endl; 
      } 
      if(k%4==3){ 
        cout<<d<<endl; 
      } 
      if(k%4==0){ 
        cout<<e<<endl; 
      } 
    } 
  } 
  return 0; 
} 