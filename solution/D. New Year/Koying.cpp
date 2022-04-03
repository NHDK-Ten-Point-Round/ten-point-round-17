#include <bits/stdc++.h>

using namespace std;

#define MAXN 200000

int n, m, cnt = 0, change = 0;
int x[MAXN], tmp[MAXN];
vector<int> G[MAXN];
bitset<MAXN> vis;

bool dfs(int i, int dep) {
    vis[i] = true;
    cnt++;
    if (tmp[i] == -1) {
        tmp[i] = dep % 2;
        if (tmp[i] != x[i]) {
            change++;
        }
    }
    else if (dep % 2 != tmp[i]) {
        return false;
    }
    bool yes = 1;
    for (int e: G[i]) {
        yes &= tmp[e] != tmp[i];
        if (vis[e])
            continue;
        yes &= dfs(e, dep + 1);
    }
    return yes;
}

void reset() {
    for (int i = 1; i <= n; i++)
        G[i].clear();
    vis.reset();
}

void sol() {
    cin >> n >> m;
    // reset();
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    set<int> s[MAXN];
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        // assert(s[a].count(b) == 0 && s[b].count(a) == 0);
        G[a].push_back(b);
        G[b].push_back(a);
        s[b].insert(a);
        s[a].insert(b);
    }
    
    for (int i = 1; i <= n; i++)
        tmp[i] = -1;

    bool yes = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt = 0, change = 0;
            yes &= dfs(i, 0);
            ans += min(change, cnt - change);
        }
    }
    if (yes)
	    cout << ans << endl;
	else 
		cout << -1 << endl;
}

signed main() {
    sol();

}