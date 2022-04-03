#include <bits/stdc++.h>

using namespace std;

string x[2], y[2];

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < m; i++)
        cin >> y[i];
    if (n == 1)
        x[1] = x[0];
    if (m == 1)
        y[1] = y[0];

    int q;
    while (t--) {
        cin >> q;
        q--;
        if (q % 2 == 0) // 0, 2
            cout << x[(q / 2) % 2] << endl;
        else // 1, 3
            cout << y[(q / 2) % 2] << endl;
    }
    return 0;
}