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

#define MAXN 20
#define MAXP 1000000

int n, p;

void make() {
    vector<int> v;
    v.push_back(1);
    while (v.back() < 2000) {
        int tmp = v.back();
        if (randint() % 2)
            tmp *= 2;
        else    
            tmp *= 3;
        if (tmp <= 2000)
            v.push_back(tmp);
        else
            break;
    }
    n = v.size(), p = randint() % MAXP + 1;
    cout << n << " " << p << endl;
    for (int it: v)
        cout << it << " ";
    cout << endl;
}

int main()
{
    int N = 20;
    while (N--) {
        make_file();
        int t = 1;
        while (t--)
            make();
        file.close();
    }
    return 0;
}
