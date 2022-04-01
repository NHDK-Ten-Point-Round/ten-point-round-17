#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

ifstream ifs;
ofstream file;
string dir_name = "../testdata/05_";//path

int fileId = 0;

void make_file() { // 建立檔案
    int sum = 0, cnt = 0;
    while (1) {
        string filename;
        if (fileId < 10) 
            filename += "0";
        filename += to_string(fileId);
        cerr << filename << endl;
        ifs.open(dir_name + filename + ".in");
        if (!ifs.is_open()) {
            file.open(dir_name + filename + ".in");
            fileId++;
            break;
        }
        
        ifs.close();
        fileId++;
    }
}
random_device rd;
auto tt = chrono::high_resolution_clock::now();
std::mt19937_64 gen = std::mt19937_64(tt.time_since_epoch().count());
std::uniform_int_distribution<> dis_int(1, 2000000000);
auto randint = bind(dis_int, gen);

std::uniform_real_distribution<> dis_float(0, 1);
auto randfloat = bind(dis_float, gen);


#define MAKE 1
#if MAKE
#define cout file
#endif

#define MAXN 20000
#define MAXM 100000
#define MAXK 50
#define MAXW 1000000000

int n, m, k;

void make() {
    n = MAXN;
    m = MAXM;
    k = MAXK;
    cout << n << " " << m << " " << k << endl;
    static set<int> s[MAXN + 1];
    static set<int> Node;
    Node.clear();
    for (int i = 0; i < m; i++) {
        int a = randint() % n + 1;
        int b = randint() % n + 1;
        int c = randint() % MAXW + 1;
        while (s[a].count(b) || s[b].count(a) || a == b) {
            a = randint() % n + 1;
            b = randint() % n + 1;
        }
        s[a].insert(b);
        s[b].insert(a);
        cout << a << " " << b << " " << c << endl;
        Node.insert(a);
        Node.insert(b);
    }
    int x, y;
    vector<int> v, vv;
    v.clear();
    vv.clear();
    for (int it: Node)
        v.push_back(it);
    for (int i = 1; i <= n; i++) {
        if (!Node.count(i))
            vv.push_back(i);
    }
    random_shuffle(v.begin(), v.end());
    random_shuffle(vv.begin(), vv.end());

    if (randint() % 3 && vv.size() > 2) {
        x = vv[vv.size() - 2];
        y = vv[vv.size() - 1];
    }
    else {
        x = v[0];
        y = v[1];
    }
    cout << x << " " << y << endl;
}

signed main()
{
    int N = 10;
    while (N--) {
        make_file();
        int t = 1;
        while (t--)
            make();
        file.close();
    }
    return 0;
}