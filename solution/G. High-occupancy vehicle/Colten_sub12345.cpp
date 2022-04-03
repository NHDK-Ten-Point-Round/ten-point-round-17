#include <bits/stdc++.h> 
  
#define int long long 
  
#define f first 
  
#define s second 
  
using namespace std; 
  
vector <pair<int,int>> a[20005]; 
  
int dis[200005][55]; 
  
void dijkstra(int x,int y,int k) 
{    
    priority_queue <pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq; 
      
    dis[x][k] = 0; 
      
    pq.push({0,{x,k}}); 
      
    while( pq.size() != 0 ) 
    { 
        pair<int,pair<int,int>> u = pq.top(); 
          
        pq.pop(); 
          
        if( u.f > dis[u.s.f][u.s.s] ) continue; 
          
        for( auto i : a[u.s.f] ) 
        { 
            for(int j=0;j<=u.s.s;j++) 
            { 
                if( u.f + i.s / ( 1LL << ( u.s.s - j ) ) < dis[i.f][j]  ) 
                { 
                    dis[i.f][j] = u.f + i.s / ( 1LL << ( u.s.s - j ) ); 
                      
                    pq.push({dis[i.f][j],{i.f,j}}); 
                } 
            } 
        } 
    } 
      
    return; 
} 
signed main(void) 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
      
    int n,m,k; 
      
    cin >> n >> m >> k; 
      
    int u1,u2; 
      
    for(int i=0;i<m;i++) 
    { 
        int x,y,w; 
          
        cin >> x >> y >> w; 
          
        a[x].push_back({y,w}); 
    } 
      
    for(int i=0;i<=n;i++) 
    { 
        for(int j=0;j<=k;j++) dis[i][j] = 1e18; 
    } 
      
    cin >> u1 >> u2; 
      
    dijkstra(u1,u2,k); 
      
    if( dis[u2][0] == 1e18 ) cout << -1 << "\n"; 
      
    else cout << dis[u2][0] << "\n"; 
}