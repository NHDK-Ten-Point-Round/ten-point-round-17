#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream in;
ofstream out;
string indir = "../testdata/02_2_"; //input path
string outdir = "../testdata/02_2_";//output path
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

#define MAXN 20
#define MAXP 1000000

int n, p;
int d[MAXN];
int dp[MAXP * 2 + 1];


void sol() {
    cin >> n >> p;
    for (int i = 1; i <= 2 * p; i++)
        dp[i] = 1e12;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    dp[0] = 0;
    sort(d, d + n);
    for (int i = 0; i <= 2 * p; i++) {
        for (int j = 0; j < n && d[j] + i <= 2 * p; j++) {
            dp[i + d[j]] = min(dp[i + d[j]], dp[i] + 1);
        }
    }
    pair<int, int> ans = {1e12, 0};
    for (int i = p; i <= 2 * p; i++) {
        ans = min(ans, {dp[i] + dp[i - p], i});
        // cout << i << " " << dp[i] + dp[p - i] << endl;
    }

    cout << ans.second << " " << ans.first << endl;
}


/************************************ solution space ************************************/

signed main()
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