#include <bits/stdc++.h>

using namespace std;

#define MAXN 25

int n, m;
int d[MAXN];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> d[i];

    bool check = 1;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        check &= d[u] != d[v];
    }
    cout << (check ? 0 : -1) << endl;
} 