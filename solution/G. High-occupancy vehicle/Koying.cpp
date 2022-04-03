#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define put(x) cout << x << endl;
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 20005
#define MAXM 1000005 
int n, m, k, x, y;
int dis[55][MAXN];
vector<pii> G[MAXN];

void dijkstra(int t) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i = 1; i <= n; i++) {
		if (dis[t][i] < INF) {
			pq.push({dis[t][i], i});
		}
	}
	while (pq.size()) {
		pii now = pq.top();
		pq.pop();
		if (now.F != dis[t][now.S])
			continue;
		for (pii e: G[now.S]) {
			if (dis[t][e.F] > now.F + e.S) {
				dis[t][e.F] = now.F + e.S;
				pq.push({now.F + e.S, e.F});
			}
		}
	}
}

void sol() {
	cin >> n >> m >> k;
	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		G[a].pb({b, c});
	}
	cin >> x >> y;
	MEM(dis, 63);
	dis[0][x] = 0;
	for (int i = 0; i <= k; i++) {
		dijkstra(i);
		for (int j = 1; j <= n; j++) {
			for (pii it: G[j]) {
				for (int t = i + 1; t <= k; t++) {
					if (dis[t][it.F] > dis[i][j] + (it.S >> (t - i))) {
						dis[t][it.F] = dis[i][j] + (it.S >> (t - i));
					}
				}
			}
			
		}
	}
	int ans = INF;
	for (int t = 0; t <= k; t++)
		cmin(ans, dis[t][y]);
	if (ans >= INF)
		cout << -1 << endl;
	else
		cout << ans << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}