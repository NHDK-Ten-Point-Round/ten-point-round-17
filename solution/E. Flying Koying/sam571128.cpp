#include <bits/stdc++.h>
 
#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using namespace std;
 
const int N = 5e3+5;
int dp[N][N], h[N];
 
signed main(){
    fastio
    int n,r,k;
    cin >> n >> r >> k;
 
    for(int i = 1;i <= n;i++)
        cin >> h[i];
 
    int ans = 0;
 
    for(int j = 1;j <= k;j++){
        deque<pair<int,int>> dq;
        for(int i = 1;i <= n;i++){
            while(!dq.empty()&&dq.front().second < i - r) dq.pop_front();
            while(!dq.empty()&&dq.back().first <= dp[i-1][j-1]+h[i-1]) dq.pop_back();
            dq.push_back({dp[i-1][j-1]+h[i-1],i-1});
 
            dp[i][j] = dq.front().first;
            ans = max(dp[i][j],ans);
        }
    }
 
    cout << ans << "\n";
}