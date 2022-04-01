#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream in;
ofstream out;
string indir = "../testdata/04_"; //input path
string outdir = "../testdata/04_";//output path
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
#define int long long
using namespace std;

#define pii pair<int, int>
#define max(a, b) (a > b ? a : b)
#define F first
#define S second


#define MAXN 5005
#define MAXK 5005

int n, r, k, x;
int h[MAXN];
int dp[MAXK][MAXN];

void sol() {
    cin >> n >> r >> k;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= k; i++) {
        deque<pii> dq;
        for (int j = 1; j < n; j++) {
            while (dq.size() && dq.back().F < dp[i - 1][j] + h[j]) {
                dq.pop_back();
            }
            if (dq.size() && dq.front().S < j + 1 - r)
                dq.pop_front();
            dq.push_back({dp[i - 1][j] + h[j], j});
            dp[i][j + 1] = max(dp[i][j + 1], dq.front().F);
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++)
            ans = max(ans, dp[i][j]);
    }
    cout << ans << endl;
}

/************************************ solution space ************************************/

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N = 25; // number of input data
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