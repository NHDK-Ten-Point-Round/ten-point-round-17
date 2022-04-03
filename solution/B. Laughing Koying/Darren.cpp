#include<bits/stdc++.h> 
using namespace std; 
#define int long long 
int INF=1e18; 
  
signed main(){ 
  ios_base::sync_with_stdio(false); 
  cin.tie(0); 
  int n,k;cin>>n>>k; 
  vector<int> a(n),b(n); 
  for(int i=0;i<n;i++){ 
    cin>>a[i]; 
  } 
  for(int i=0;i<n;i++){ 
    cin>>b[i]; 
    if(b[i]<k){ 
      b[i]=0; 
    } 
  } 
  int cnt=0; 
  vector<int> ans; 
  for(int i=0;i<n;i++){ 
    cnt+=b[i]; 
    if(cnt>=a[i]){ 
      ans.push_back(i+1); 
      cnt=0; 
    } 
  } 
  cout<<ans.size()<<endl; 
  for(int i:ans){ 
    cout<<i<<' '; 
  } 
  
  return 0; 
} 