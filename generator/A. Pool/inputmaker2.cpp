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
        cerr << fileId << endl;
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

string Name[] = {"Colten", "Koying", "HPK"};
int n, m, t;

void make() {
    n = randint() % 2 + 1;
    m = 3 - n;
    t = randint() % 1000 + 1;
    cout << n << " " << m << " " << t << endl;

    random_shuffle(Name, Name + 3);

    for (int i = 0; i < n; i++)
        cout << Name[i] << endl;
    for (int i = 0; i < m; i++)
        cout << Name[2 - i] << endl;


    while (t--) {
        cout << randint() % (int)(1e9) + 1 << endl;
    }
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
