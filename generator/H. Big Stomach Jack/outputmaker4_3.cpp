#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream in;
ofstream out;
string indir = "../testdata/04_3_"; //input path
string outdir = "../testdata/04_3_";//output path
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

#define MAXN 100005

const int INF = 1e18;

int n, q, k;
int y[MAXN];

struct Node {
    int l, r, mn, mnpos, sum;

    Node operator +(Node _a) {
        Node tmp;
        tmp.mn = mn, tmp.mnpos = mnpos;
        tmp.sum = sum + _a.sum;
        if (_a.mn < mn) {
            tmp.mn = _a.mn;
            tmp.mnpos = _a.mnpos;
        }
        return tmp;
    }

    void operator =(Node _a) {
        mn = _a.mn;
        mnpos = _a.mnpos;
        sum = _a.sum;
        return;
    }
} seg[MAXN << 2];

void build(int id, int l, int r) {
    seg[id].l = l, seg[id].r = r;
    if (l == r) {
        seg[id].mn = y[l];
        seg[id].mnpos = l;
        seg[id].sum = y[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

void update(int id, int pos, int val) {
    int l = seg[id].l, r = seg[id].r;
    if (l > pos || r < pos)
        return;
    if (l == r) {
        seg[id].mn += val;
        seg[id].sum += val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, pos, val);
    update(id * 2 + 1, pos, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

Node query(int id, int ql, int qr) {
    int l = seg[id].l, r = seg[id].r;
    Node tmp;
    tmp.mn = INF, tmp.mnpos = INF, tmp.sum = 0;
    if (l > qr || r < ql)
        return tmp;
    if (ql <= l && r <= qr) {
        return seg[id];
    }
    int mid = (l + r) / 2;
    return query(id * 2, ql, qr) + query(id * 2 + 1, ql, qr);
}

void sol() {
    cin >> n >> q >> k;
    // k = 1;
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
    }
    build(1, 1, n);

    int a;
    while (q--) {
        cin >> a;
        int l = 0, r = n - a + 1, mid = (l + r + 1) / 2;
        while (l < r) {
            mid = (l + r + 1) / 2;
            if (mid == 0) {
                l = 0;
                break;
            }
            Node qry = query(1, a, a + mid - 1);
            if (sqrt(qry.mn) < mid)
                r = mid - 1;
            else 
                l = mid;
        }
        cout << l << " ";
        if (l != 0) {
            Node res = query(1, a, a + l - 1);
            cout << res.sum << endl;
            update(1, res.mnpos, l * k);
        }
        else {
            cout << 0 << endl;
        }
    }
}




/************************************ solution space ************************************/

signed main()
{
    int N = 5; // number of input data
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