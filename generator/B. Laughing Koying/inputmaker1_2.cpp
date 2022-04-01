#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream ifs;
ofstream file;
string dir_name = "../testdata/01_2_";//path

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
#define MAXNA_I 1000000000

int a[MAXN], l[MAXN];

void make() {
    int n = 100000, k = 0;
    if (randint() % 2)
        n = randint() % MAXN + 1;
    cout << n << " " << k << endl;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        l[i] = randint() % MAXNA_I + 1;
        sum += l[i];
        if (randint() % 5 == 0) {
            a[i] = l[i];
            sum = 0;
        }
        else {
            a[i] = randint() % MAXNA_I + 1;
            if (sum >= a[i]) {
                sum = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << l[i] << " ";
    cout << endl;
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
