#include <bits/stdc++.h>

using namespace std;

#define MAXP 1000005

int n, p;
int d[20], dp[MAXP * 2];

signed main() {
    cin >> n >> p;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    sort(d, d + n, greater<int>());

    for (int i = 1; i <= 2 * p; i++) {
        int tmp = i;
        for (int j = 0; j < n; j++) {
            dp[i] += tmp / d[j];
            tmp %= d[j];
        }
    }

    pair<int, int> ans = {1e12, 0};
    for (int i = p; i <= 2 * p; i++) {
        ans = min(ans, {dp[i] + dp[i - p], i});
    }
    cout << ans.second << " " << ans.first << endl;
}