#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream in;
ofstream out;
string indir = "../testdata/03_"; //input path
string outdir = "../testdata/03_";//output path

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

#define MAXN 100001

int n, m, cnt = 0, change = 0;
int x[MAXN], tmp[MAXN];
static vector<int> G[MAXN];
static bitset<1000000> vis;

inline bool dfs(int i, int dep) {
    vis[i] = true;
    cnt++;
    if (tmp[i] == -1) {
        tmp[i] = dep % 2;
        if (tmp[i] != x[i])
            change++;
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
    reset();
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        if (a > n) {
            cerr << a << endl;
        }
        if (b > n)
            cerr << b << endl;
        assert(a <= n && b <= n);
    }
    
    for (int i = 1; i <= n; i++)
        tmp[i] = -1;

    bool yes = 1;
    int ans = 0;
    for (int i = 1; i <= n && yes; i++) {
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



/************************************ solution space ************************************/

#define TERMINAL 0

int main()
{
    int N = 20 - 10; // number of input data
    ios::sync_with_stdio(0), cin.tie(0);
    #if TERMINAL
    indir = "./New Year/testdata/03_";
    outdir = "./New Year/testdata/03_";
    #endif
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