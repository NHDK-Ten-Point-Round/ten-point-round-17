#include <bits/stdc++.h> 
  
#define int long long 
  
using namespace std; 
  
int a[100005]; 
  
int n,k,q; 
  
struct Node{ 
    int sum,mn,p; 
}; 
  
Node seg[400005]; 
  
void build(int index,int l,int r) 
{ 
    if( l == r ) 
    { 
        seg[index].sum = a[l]; 
        seg[index].mn = a[l]; 
        seg[index].p = l; 
          
        return; 
    } 
    else
    { 
        int mid = ( l + r ) / 2; 
          
        build(index*2,l,mid); 
        build(index*2+1,mid+1,r); 
          
        seg[index].sum = seg[index*2].sum + seg[index*2+1].sum; 
        seg[index].mn = min(seg[index*2].mn,seg[index*2+1].mn); 
          
        if( seg[index*2].mn <= seg[index*2+1].mn ) seg[index].p = seg[index*2].p; 
          
        else seg[index].p = seg[index*2+1].p; 
    } 
      
    return; 
} 
void update(int pos,int val,int index,int l,int r) 
{ 
    if( l == r ) 
    { 
        seg[index].sum += val; 
        seg[index].mn += val; 
          
        return; 
    } 
    else
    { 
        int mid = ( l + r ) / 2; 
          
        if( pos <= mid ) update(pos,val,index*2,l,mid); 
          
        else update(pos,val,index*2+1,mid+1,r); 
    } 
      
    seg[index].sum = seg[index*2].sum + seg[index*2+1].sum; 
    seg[index].mn = min(seg[index*2].mn,seg[index*2+1].mn); 
      
    if( seg[index*2].mn <= seg[index*2+1].mn ) seg[index].p = seg[index*2].p; 
      
    else seg[index].p = seg[index*2+1].p; 
} 
Node query(int ql,int qr,int index,int l,int r) 
{ 
    if( ql <= l && r <= qr ) return seg[index]; 
      
    int mid = ( l + r ) / 2; 
      
    if( qr <= mid ) return query(ql,qr,index*2,l,mid); 
      
    else if( ql > mid ) return query(ql,qr,index*2+1,mid+1,r); 
      
    else
    { 
        Node u1 = query(ql,qr,index*2,l,mid); 
          
        Node u2 = query(ql,qr,index*2+1,mid+1,r); 
          
        Node u3; 
          
        u3.sum = u1.sum + u2.sum; 
        u3.mn = min(u1.mn,u2.mn); 
          
        if( u1.mn <= u2.mn ) u3.p = u1.p; 
          
        else u3.p = u2.p; 
          
        return u3; 
    } 
} 
signed main(void) 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
      
    cin >> n >> q >> k; 
      
    for(int i=1;i<=n;i++) cin >> a[i]; 
      
    build(1,1,n); 
      
    while(q--) 
    { 
        int s; 
          
        cin >> s; 
          
        int l = s,r = n; 
          
        while( l <= r ) 
        { 
            int mid = ( l + r ) / 2; 
              
            int u = query(s,mid,1,1,n).mn; 
              
            if( sqrt(u) < mid - s + 1 ) r = mid - 1; 
              
            else l = mid + 1; 
        } 
          
        Node ans = query(s,r,1,1,n); 
          
        cout << r - s + 1 << " " << ans.sum << "\n"; 
          
        update(ans.p,(r-s+1)*k,1,1,n);  
    } 
}