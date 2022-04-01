#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream ifs;
ofstream file;
string dir_name = "../testdata/03_3_";//path

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

#define MAXN 100000
#define MAXQ 100000
#define MAXY 1000000000
int n, q, k = 0;

void make() {
    n = MAXN, q = MAXQ;
    // if (randint() % 2)
    //     n = randint() % MAXN + 1;
    // if (randint() % 2)
    //     q = randint() % MAXN + 1;
    cout << n << " " << q << " " << k << endl;
    for (int i = 1; i <= n; i++) {
        cout << MAXY << " ";
    }
    cout << endl;
    while (q--) {
        cout << 1 << endl;
    }
}

int main()
{
    int N = 5;
    while (N--) {
        make_file();
        int t = 1;
        while (t--)
            make();
        file.close();
    }
    return 0;
}
