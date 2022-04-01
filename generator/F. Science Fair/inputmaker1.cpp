#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream ifs;
ofstream file;
string dir_name = "../testdata/01_";//path

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

#define MAXN 10

int n, m;

void make() {
    n = m = 10;
    cout << n << " " << m << endl;

    int num = randint() % 7 + 1;
    if (randint() % 3) {
        int dif = randint() % n;
        int dif2 = randint() % n;
        if (randint() % 2)
            dif2 = dif;
        for (int i = 0; i < n; i++) { //s1
            if (i == dif) {
                cout << randint() % 7 + 1;
            }
            else {
                cout << num;
            }
        }
        cout << endl;

        for (int i = 0; i < m; i++) { //s2
            if (i == dif2) {
                cout << randint() % 7 + 1;
            }
            else {
                cout << num;
            }
        }
        cout << endl;
    }
    else {
        for (int i = 0; i < n; i++)
            cout << num;
        cout << endl;
        
        for (int i = 0; i < m; i++)
            cout << num;
        cout << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N = 30;
    while (N--) {
        make_file();
        int t = 1;
        while (t--)
            make();
        file.close();
    }
    return 0;
}
