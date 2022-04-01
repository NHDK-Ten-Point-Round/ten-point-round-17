#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream in;
ofstream out;
string indir = "../testdata/01_"; //input path
string outdir = "../testdata/01_";//output path
int fileId = 0;

void start() { // 建立檔案 
    while(1) {
        string filename;
        if (fileId < 10)
            filename += "0";
        filename += to_string(fileId);
        in.open(outdir + filename + ".out");
        fileId++;
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


string x[2], y[2];

void sol() {
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
}


/************************************ solution space ************************************/

int main()
{
    int N = 10; // number of input data
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