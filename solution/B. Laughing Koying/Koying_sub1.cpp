#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN 1000005

int n, k;
int a[MAXN], l[MAXN];
vector<int> t;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> l[i];

    int cnt = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        sum += l[i];
        if (sum >= a[i]) {
            sum = 0;
            cnt++;
            t.push_back(i + 1);
        }
    }
    
    cout << cnt << endl;

    for (int it: t)
        cout << it << " ";
    cout << endl;

    return 0;
}