#include <bits/stdc++.h>

using namespace std;

#define MAXN 5005

int n, r, k;
int h[MAXN];
int dp[MAXN][MAXN];


signed main() {
    cin >> n >> r >> k;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int ans = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i][j - 1];
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + h[j - 1]);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}