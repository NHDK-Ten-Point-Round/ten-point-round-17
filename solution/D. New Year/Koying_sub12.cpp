#include <bits/stdc++.h>

using namespace std;

#define MAXN 25

int n, m;
int d[MAXN];
vector<pair<int, int>> G;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> d[i];

    int ans = 1e9;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        G.push_back({u, v});
    }

    for (int i = 0; i < (1 << n); i++) {
        bool check = 1;
        for (int j = 0; j < G.size(); j++) {
            check &= 
                (bool)(i & (1 << (G[j].first - 1))) != 
                (bool)(i & (1 << (G[j].second - 1)));
        }
        if (check) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                cnt += d[j] != (bool)(i & (1 << (j - 1)));
            }
            ans = min(ans, cnt);
        }
    }

    if (ans != 1e9)
        cout << ans << endl;
    else   
        cout << -1 << endl;
} 