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
#define MAXM 1000000
#define min(a, b) (a < b ? a : b)

int n, m;
int d[MAXN + 1];

void make() {
    if (randint() % 2)
        n = randint() % MAXN + 1;
    if (n == 1)
        n = 2;
    m = randint() % (n / 2 * min(10, n - n / 2)) + 1;
    cout << n << " " << m << endl;
    vector<int> v;
    for (int i = 1; i <= n; i++)
        v.push_back(i);
    random_shuffle(v.begin(), v.end());
    vector<int> F, S;
    for (int i = 0; i < n / 2; i++) {
        F.push_back(v[i]);
        d[v[i]] = 0;
    }
    for (int i = n / 2; i < n; i++) {
        S.push_back(v[i]);
        d[v[i]] = 1;
    }
    vector<pair<int, int>> E;
    for (int it: F) {
        random_shuffle(S.begin(), S.end());
        for (int i = 0; i < min(S.size(), 10); i++)
            E.push_back({it, S[i]});
    }

    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
    cout << endl;

    if (randint() % 2 && m >= 3) {
        random_shuffle(F.begin(), F.end());
        random_shuffle(S.begin(), S.end());
        if (F.size() >= 3) {
            cout << F[0] << " " << F[1] << endl;
            cout << F[1] << " " << F[2] << endl;
            cout << F[0] << " " << F[2] << endl;
            m -= 3;
        }
        else if (S.size() >= 3) {
            cout << S[0] << " " << S[1] << endl;
            cout << S[1] << " " << S[2] << endl;
            cout << S[0] << " " << S[2] << endl;
            m -= 3;
        }
    }
    random_shuffle(E.begin(), E.end());
    for (int i = 0; i < m; i++)
        cout << E[i].first << " " << E[i].second << endl;
}

int main()
{
    int N = 15;
    while (N--) {
        make_file();
        int t = 1;
        while (t--)
            make();
        file.close();
    }
    return 0;
}
