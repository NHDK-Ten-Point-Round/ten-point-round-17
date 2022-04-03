#include <bits/stdc++.h> 
#define int long long

using namespace std;

#define MAXN 20
#define MAXP 1000000

int n, p;
int d[MAXN];
int dp[MAXP * 2 + 1];


void sol() {
    cin >> n >> p;
    for (int i = 1; i <= 2 * p; i++)
        dp[i] = 1e12;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    dp[0] = 0;
    sort(d, d + n);
    for (int i = 0; i <= 2 * p; i++) {
        for (int j = 0; j < n && d[j] + i <= 2 * p; j++) {
            dp[i + d[j]] = min(dp[i + d[j]], dp[i] + 1);
        }
    }
    pair<int, int> ans = {1e12, 0};
    for (int i = p; i <= 2 * p; i++) {
        ans = min(ans, {dp[i] + dp[i - p], i});
    }

    cout << ans.second << " " << ans.first << endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    sol();
}