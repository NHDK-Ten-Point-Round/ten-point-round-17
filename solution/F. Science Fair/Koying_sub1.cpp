#include <iostream>

using namespace std;

int main() {
    int n, m;
    string s1, s2;
    cin >> n >> m;
    cin >> s1 >> s2;

    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += s1[i] != s2[i];
    if (cnt < 2)
        cout << 10 << endl;
    else
        cout << -1 << endl;
}