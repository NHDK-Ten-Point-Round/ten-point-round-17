#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream ifs;
ofstream file;
string dir_name = "../testdata/03_";//path

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

#define MAXN 100

int n, m;

void make() {
    n = m = MAXN;
    int tmp = randint() % MAXN + 1;
    n = (tmp >= 50 ? tmp : MAXN);
    tmp = randint() % MAXN + 1;
    m = (tmp >= 50 ? tmp : MAXN);
    if (n < m)
        swap(n, m);

    cout << n << " " << m << endl;

    
    int num = randint() % 7 + 1;
    string s1;
    for (int i = 0; i < n; i++) {
        int tmp = randint() % num + 1;
        cout << randint() % num + 1;
        s1 += to_string(tmp);
    }
    cout << endl;

    for (int i = 0; i < m; i++) {
        if (randint() % 20)
            cout << s1[i];
        else
            cout << randint() % num + 1;
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N = 40;
    while (N--) {
        make_file();
        int t = 1;
        while (t--)
            make();
        file.close();
    }
    return 0;
}
