#include <bits/stdc++.h>

using namespace std;

string x, y;

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    cin >> x >> y;

    int q;
    while (t--) {
        cin >> q;
        q--;
        if (q % 2)
            cout << y << endl;
        else 
            cout << x << endl;
    }
    return 0;
}