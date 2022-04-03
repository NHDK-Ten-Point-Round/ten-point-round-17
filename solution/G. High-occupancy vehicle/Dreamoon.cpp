/*{{{*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
 
const int SIZE = 20'005;
const LL INF = 1e18;
int N,M,K,st,ed;
LL dp[SIZE][51];
VPII e[SIZE];
void update(LL &x, LL v) {
    if(x>v)x=v;
}
bitset<SIZE>u;
void run(int lv){
    priority_queue<pair<LL,int>>pq;
    FOR(i,1,N){
        if(dp[i][lv]!=INF){
            pq.push(MP(-dp[i][lv],i));
        }
    }
    u.reset();
    while(!pq.empty()){
        auto me=pq.top();
        pq.pop();
        int x=me.S;
        if(u[x])continue;
        u[x]=1;
        for(auto &[y,v]: e[x]) {
            if(dp[y][lv]>v-me.F){
                dp[y][lv]=v-me.F;
                pq.push({-dp[y][lv], y});
            }
        }
    }
}
void solve() {
    R(st,ed);
    FOR(i,1,N)FOR(j,0,K)dp[i][j]=INF;
    dp[st][0]=0;
    REP(i,K+1){
        run(i);
        FOR(x,1,N){
            for(auto &[y,v]: e[x]){
                FOR(j,i+1,K){
                    update(dp[y][j],dp[x][i]+(v>>j-i));
                }
            }
        }
    }
    if(dp[ed][K]==INF)W(-1);
    else W(dp[ed][K]);
}
void input() {
    R(N,M,K);
    REP(i,M){
        int x,y,v;
        R(x,y,v);
        e[x].PB({y,v});
    }
}
int main(){
    input();
    solve();
    return 0;
}