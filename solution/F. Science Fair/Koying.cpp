#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

#define MAXN 101

int n, m;
string s1, s2;

void sol() {   
    cin >> n >> m;
    cin >> s1;
    cin >> s2;

    int ans = 0;
    int dp[MAXN][MAXN];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            memset(dp, 0x3f, sizeof(dp));
            for (int oao = 0; oao <= max(n, m); oao++)
                dp[0][oao] = oao, dp[oao][0] = oao;
            for (int x = 1; x + i <= n; x++) {
                for (int y = 1; y + j <= m; y++) {
                    if (s1[x + i - 1] == s2[y + j - 1])
                        dp[x][y] = min(dp[x][y], dp[x - 1][y - 1]);
                    else {
                        dp[x][y]
                            = min(dp[x - 1][y - 1], min(dp[x - 1][y], dp[x][y - 1])) + 1;
                    }

                    if (x >= 10 && x == y) {
                        int dis = dp[x][y];
                        if (dis * 10 <= x)
                            ans = max(ans, x);
                        // cout << i << " " << j << " " << dis << " " << x << " " << dis << endl;
                    }
                }
            }
        }
    }
    if (ans >= 10)
        cout << ans << endl;
    else
        cout << -1 << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sol();
}