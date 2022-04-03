#include <bits/stdc++.h>
 
#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
const int MAXN = 1e5+5;
 
struct node{
    int sum, mn, mnpos;
};
 
node tr[MAXN*4];
int arr[MAXN]; 
 
int fsqrt(int x){
    return floor(sqrt(x));
}
 
node combine(node a, node b){
    if(a.mn <= b.mn){
        return {a.sum+b.sum,min(a.mn,b.mn),a.mnpos};
    }
    return {a.sum+b.sum,min(a.mn,b.mn),b.mnpos};
}
 
void build(int idx, int l, int r){
    if(l==r){
        tr[idx] = {arr[l],fsqrt(arr[l]),l}; 
    }else{
        int m = (l+r)/2;
        build(idx*2,l,m); 
        build(idx*2+1,m+1,r); 
        tr[idx] = combine(tr[idx*2],tr[idx*2+1]); 
    }
}
 
void modify(int pos, int val, int idx, int l, int r){
    if(l == r){
        arr[l] += val;
        tr[idx] = {arr[l],fsqrt(arr[l]),l}; 
        return;
    }
    int m = (l+r)/2;
    if(pos > m) modify(pos, val, idx*2+1, m+1, r);
    if(pos <= m) modify(pos, val, idx*2, l, m);
    tr[idx] = combine(tr[idx<<1],tr[idx<<1|1]);
}
 
node query(int ql, int qr, int idx, int l, int r){
    if(ql <= l && r <= qr){
        return tr[idx];
    }
    int mid = l+r>>1;
    if(qr <= mid) return query(ql,qr,idx<<1,l,mid);
    if(ql > mid) return query(ql,qr,idx<<1|1,mid+1,r);
    return combine(query(ql,qr,idx<<1,l,mid),query(ql,qr,idx<<1|1,mid+1,r));
}
 
signed main(){
    fastio
    int n,q,k;
    cin >> n >> q >> k;
 
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    build(1,1,n);
 
    while(q--){
        int l;
        cin >> l;
 
        int ll = l, rr = n;
        while(ll < rr){
            int mid = (ll+rr+1)/2;
 
            if(query(l,mid,1,1,n).mn >= (mid-l+1)) ll = mid;
            else rr = mid-1;
        }
 
        auto [sum, mn, pos] = query(l,ll,1,1,n);
        cout << ll-l+1 << " " << sum << "\n";
        modify(pos,(ll-l+1)*k,1,1,n);
    }
}