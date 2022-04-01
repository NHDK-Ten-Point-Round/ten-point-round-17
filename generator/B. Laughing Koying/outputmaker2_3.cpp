#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream in;
ofstream out;
string indir = "../testdata/02_3_"; //input path
string outdir = "../testdata/02_3_";//output path
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

#define MAXN 100005

int n, k;
int a[MAXN], l[MAXN];

void sol() {
    cin >> n >> k;
    assert(n <= 100000 && k <= 100000);
    vector<int> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        assert(a[i] <= 1000000000);
    }
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        assert(l[i] <= 1000000000);
    }

    int cnt = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        if (l[i] >= k)
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
}



/************************************ solution space ************************************/

int main()
{
    int N = 5; // number of input data
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