#include <bits/stdc++.h>
#define ll long long
#define int long long

using namespace std;

ifstream ifs;
ofstream file;
string dir_name = "../testdata/03_noSPFA_";//path

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
#define MAXK 0
#define MAXW 1000000000
int n, m, k;
int dep[MAXN + 1];

void make() {
    n = MAXN;
    m = MAXM;
    m = min(m, n * (n - 1) / 2);
    k = MAXK;
    dep[1] = 1;
    cout << n << " " << m << " " << k << endl;
    for (int i = 2; i <= n; i++) {
        int b = i, a;
        int c = randint() % MAXW + 1;
        if (i < 6) {
            a = randint() % (i - 1) + 1;
        }
        else {
            a = i - (randint() % 5 + 1);
        }
        cout << a << " " << b << " " << c << endl;
        dep[b] = dep[a] + 1;
    }
    m -= (n - 1);
    while (m--) {
        int a = randint() % n + 1;
        int b = randint() % n + 1;
        while (a == b)
            b = randint() % n + 1;
        if (a > b)
            swap(a, b);
        int c = randint() % 5 + dep[b] - dep[a];
        cout << a << " " << b << " " << c << endl;
    }
    int x = 1;
    int y = randint() % n + 1;
    while (x == y)
        y = randint() % n + 1;
    cout << x << " " << y << endl;
}

signed main()
{
    int N = 11 - 10;
    while (N--) {
        make_file();
        int t = 1;
        while (t--)
            make();
        file.close();
    }
    return 0;
}
