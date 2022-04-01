#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream ifs;
ofstream file;
string dir_name = "../testdata/02_";//path

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

#define MAXN 5
#define MAXM 5
#define MAXK 5
#define MAXW 1000000000

int n, m, k;

void make() {
    n = randint() % (MAXN - 1) + 2;
    m = randint() % MAXM + 1;
    m = min(m, n * (n - 1) / 2);
    k = randint() % (MAXK + 1);
    cout << n << " " << m << " " << k << endl;
    set<int> s[MAXN + 1];
    set<int> Node;
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
    vector<int> v;
    for (int it: Node)
        v.push_back(it);
    random_shuffle(v.begin(), v.end());
    x = v[0], y = v[1];
    cout << x << " " << y << endl;
}

int main()
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
