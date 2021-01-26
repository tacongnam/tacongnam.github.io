/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: RTREE2 **/

#include <bits/stdc++.h>

#define task                "RTREE2"
#define fi(a)               freopen(a, "r", stdin)
#define fo(a)               freopen(a, "w", stdout)
#define rep(i, a, b)        for(int (i) = (a); (i) <= (b); ++(i))
#define repd(i, a, b)       for(int (i) = (a); (i) >= (b); --(i))
#define repa(a, u)          for(auto (a) : (u))

#define bit(a, i)           (((a) >> (i)) & 1)
#define mask(i)             (1LL << (i))
#define turnon(a, i)        ((a) | mask(i))
#define turnoff(a, i)       ((a) & (~mask(i)))

#define ft                  first
#define sd                  second
#define pb                  push_back
#define mp                  make_pair

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#define rand()              rng()

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minqueue;
typedef priority_queue<pii> maxqueue;

const int maxn = 3e3 + 5;
const long long mod = 1e9 + 7;
const int base = 26;
const double pi = 3.14159265359;

int counterr = 0;

#define start_debug cerr << "Debug status: \n"
#define debug(...)  cerr << "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "] "
#define debuga(...) cerr << "[" << #__VA_ARGS__ << ": "; counterr = 0; for(auto v : __VA_ARGS__){ counterr++, cerr << v; cerr << ((counterr != __VA_ARGS__.size()) ? "," : "");} cerr << "] "
#define end_debug   cerr << "\n"

/** End of template **/
/** Nếu bạn mất niềm tin vào cuộc sống, hãy đọc code này **/

int n, res, x[maxn], d[maxn], y[maxn], a[maxn][maxn];
vector <int> g[maxn];

bool Find() {
    queue <int> qu;
    for(int i = 1; i <= n; i++) {
        if(x[i] == 0) {
            d[i] = 0;
            qu.push(i);
        }
        else
            d[i] = 1e9;
    }
    d[0] = 1e9;
    while(qu.size() > 0) {
        int u = qu.front();
        qu.pop();
        for(int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if(d[y[v]] == 1e9) {
                d[y[v]] = d[u] + 1;
                if(y[v] != 0)
                    qu.push(y[v]);
            }
        }
    }
    return (d[0] != 1e9);
}

bool dfs(int u) {
    if(u == 0)
        return true;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(d[y[v]] == d[u] + 1)
            if(dfs(y[v]) == true) {
                x[u] = v, y[v] = u;
                return true;
            }
    }
    d[u] = 1e9;
    return false;
}

int GhepMax() {
    while(Find() == true) {
        for(int i = 1; i <= n; i++) {
            if(x[i] == 0)
                if(dfs(i) == true)
                    res++;
        }
    }

    return res;
}

void reset() {
    rep(i, 1, n) {
        g[i].clear();
        x[i] = 0;
        y[i] = 0;
    }
    res = 0;
}

bool check(int mid) {
    reset();
    rep(i, 1, n)
        rep(j, 1, n)
            if(a[i][j] >= mid)
                g[i].pb(j);
    int d = GhepMax();
//    debug(mid), debug(d) << "\n";
    if(d == n) return true;
    return false;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    rep(i, 1, n)
        rep(j, 1, n)
            cin >> a[i][j];

    int L = 0, R = 1000000000;
    while(L <= R) {
        int mid = (L + R) / 2;
        if(check(mid) == true)
            L = mid + 1;
        else R = mid - 1;
    }

    cout << L - 1 << "\n";
}

/*
4
8 4 3 3
5 6 4 3
2 3 7 7
4 5 3 2
*/
