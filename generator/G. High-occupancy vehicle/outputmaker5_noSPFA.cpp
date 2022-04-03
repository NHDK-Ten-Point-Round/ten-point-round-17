#include <bits/stdc++.h>
// #define ll long long

using namespace std;

ifstream in;
ofstream out;
string indir = "../testdata/05_noSPFA_"; //input path
string outdir = "../testdata/05_noSPFA_";//output path
int fileId = 0;

void start() { // 建立檔案 
    while(1) {
        string filename;
        if (fileId < 10)
            filename += "0";
        filename += to_string(fileId);
        in.open(outdir + filename + ".out");
        fileId++;
        cerr << filename << endl;
        if (!in.is_open())
        {
            out.open(outdir + filename + ".out");
            in.open(indir + filename + ".in");
            break;
        }
        else
            in.close();
    }
}

#define MAKE 1
#define cin in
#if MAKE
#define cout out
#endif

/************************************ solution space ************************************/

#include <bits/stdc++.h> 

using namespace std;

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
#define MAXN 20005
#define MAXM 100005 

int n, m, k, x, y;
int dis[MAXN][101];
static vector<pii> G[MAXN];

#define piii pair<int, pair<int, int>>

void sol() {
    cin >> n >> m >> k;
    for (int i = 1; i < MAXN; i++)
        G[i].clear();
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        G[a].pb({b, c});
    }
    cin >> x >> y;
    
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.push({0, {x, 0}});
    MEM(dis, 63);
    dis[x][0] = 0;
    while (pq.size()) {
        pair<int, pii> now = pq.top();
        pq.pop();
        if (dis[now.S.F][now.S.S] != now.F)
            continue;
        for (pii e: G[now.S.F]) {
            int tmp = e.S;
            for (int i = 0; i + now.S.S <= k; i++) {
                if (dis[e.F][now.S.S + i] > tmp + now.F) {
                    dis[e.F][now.S.S + i] = tmp + now.F;
                    pq.push({dis[e.F][now.S.S + i], {e.F, now.S.S + i}});
                }
                tmp /= 2;
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= k; i++) {
        cmin(ans, dis[y][i]);
    }
    if (ans == INF) {
        cout << -1 << endl;
    }
    else
        cout << ans << endl;
}
/************************************ solution space ************************************/

signed main()
{
    int N = 11 - 10; // number of input data
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // cin >> n;
    while (N--)
    {
        start();
        int t = 1;

        while (t--)
            sol();
        out.close();
        in.close();
    }
    return 0;
}