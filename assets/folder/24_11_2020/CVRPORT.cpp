/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: CVRPORT **/

#include <bits/stdc++.h>

#define task				"CVRPORT"
#define fi(a)				freopen(a, "r", stdin)
#define fo(a)				freopen(a, "w", stdout)
#define rep(i, a, b)		for(int (i) = (a); (i) <= (b); ++(i))
#define repd(i, a, b)		for(int (i) = (a); (i) >= (b); --(i))
#define repa(a, u)			for(auto (a) : (u))

#define bit(a, i)			(((a) >> (i)) & 1)
#define mask(i)				(1LL << (i))
#define turnon(a, i)		((a) | mask(i))
#define turnoff(a, i)		((a) & (~mask(i)))

#define ft					first
#define sd 					second
#define pb					push_back
#define mp					make_pair

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#define	rand()				rng()

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minqueue;
typedef priority_queue<pii> maxqueue;

const int maxn = 1e5 + 5;
const long long mod = 1e9 + 7;
const int base = 26;
const double pi = 3.14159265359;

int counterr = 0;

#define start_debug	cerr << "Debug status: \n"
#define debug(...) 	cerr << "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "] "
#define debuga(...)	cerr << "[" << #__VA_ARGS__ << ": "; counterr = 0; for(auto v : __VA_ARGS__){ counterr++, cerr << v; cerr << ((counterr != __VA_ARGS__.size()) ? "," : "");} cerr << "] "
#define end_debug	cerr << "\n"

/** End of template **/
/** Nếu bạn mất niềm tin vào cuộc sống, hãy đọc code này **/

#define int long long
int n, k, q;
int d[17];
int a[17][17], dist[mask(16)][17], weight[mask(16)];
int dp[mask(16)][6];

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> n >> k >> q;
	rep(i, 1, n)
		cin >> d[i];
	rep(i, 0, n)
		rep(j, 0, n)
			cin >> a[i][j];

	rep(i, 1, mask(n) - 1)
		rep(j, 1, n)
			dist[i][j] = 1e18;

	rep(i, 1, n) {
		dist[mask(i - 1)][i] = a[0][i];
		weight[mask(i - 1)] = q - d[i];
	}

	rep(i, 1, mask(n) - 1) {
		rep(j, 1, n) {
			if(bit(i, j - 1) == 0)
				continue;
            weight[i] += d[j];
			rep(x, 1, n)
				if(bit(i, x - 1) == 0) {
					dist[i + mask(x - 1)][x] = min(dist[i + mask(x - 1)][x], dist[i][j] + a[j][x]);
				}
		}
	}

    rep(i, 1, mask(n) - 1)
        if(weight[i] > q)
            rep(j, 1, n)
                dist[i][j] = 1e18;

	rep(i, 0, mask(n) - 1)
		rep(j, 0, k)
			dp[i][j] = 1e18;

    dp[0][0] = 0;

	rep(i, 0, mask(n) - 1) {
		rep(j, 1, k) {
			rep(x, i + 1, mask(n) - 1) {
				if(x | i != x && weight[x - i] > q)
					continue;

                if(x == i)
                    dp[x][j] = dp[i][j - 1];
                else {
                    rep(t, 0, n - 1)
                        if(bit(x, t) == 1 && bit(i, t) == 0) {
                            dp[x][j] = min(dp[x][j], dp[i][j - 1] + dist[x - i][t + 1] + a[t + 1][0]);
                        }
                }
			}
		}
	}

    cout << dp[mask(n) - 1][k];


	//dp[last][mask] = min(D, dp[last - 1][mask \ S] + dist[S][...] + a[...][0])

	end_debug;
}
