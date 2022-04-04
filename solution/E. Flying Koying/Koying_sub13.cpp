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
            for (int l = max(0, j - r); l < j; l++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][l] + h[l]);
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << ans << endl;
}