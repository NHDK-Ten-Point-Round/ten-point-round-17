#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream in;
ofstream out;
string indir = "../testdata/02_"; //input path
string outdir = "../testdata/02_";//output path
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

#define MAXN 101

int n, m;
string s1, s2;

void sol() {   
    cin >> n >> m;
    cin >> s1;
    cin >> s2;

    int ans = 0;
    int dp[MAXN][MAXN];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            memset(dp, 0x3f, sizeof(dp));
            for (int oao = 0; oao <= max(n, m); oao++)
                dp[0][oao] = oao, dp[oao][0] = oao;
            for (int x = 1; x + i <= n; x++) {
                for (int y = 1; y + j <= m; y++) {
                    if (s1[x + i - 1] == s2[y + j - 1])
                        dp[x][y] = dp[x - 1][y - 1];
                    else {
                        dp[x][y]
                            = min(dp[x - 1][y - 1], min(dp[x - 1][y], dp[x][y - 1])) + 1;
                    }

                    if (x >= 10 && x == y) {
                        int dis = dp[x][y];
                        double res;
                        res = 1.0 - (double)(dis) / (double)(x + 1);
                        res *= 100.0;
                        if (dis * 10 <= x)
                            ans = max(ans, x);
                        // cout << i << " " << j << " " << dis << " " << x << " " << dis << endl;
                    }
                }
            }
        }
    }
    if (ans >= 10)
        cout << ans << endl;
    else
        cout << -1 << endl;
}
/************************************ solution space ************************************/

int main()
{
    int N = 30; // number of input data
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