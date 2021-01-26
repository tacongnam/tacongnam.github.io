/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: CHANGE2D **/

#include <bits/stdc++.h>

#define task				"CHANGE2D"
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

const int maxn = 1e3 + 5;
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

int m, n, k, q;
ll a[maxn][maxn], r[maxn][maxn], s[maxn][maxn];
ll ans;

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
//	fi(task".inp"), fo(task".out");
	
	cin >> m >> n >> k;
	rep(i, 1, m)
		rep(j, 1, n)
			cin >> a[i][j];

	cin >> q;
	while(q--) {
		int i1, j1, i2, j2;
		ll d;
		cin >> i1 >> j1 >> i2 >> j2 >> d;
		r[i1][j1] += d, r[i2 + 1][j1] -= d;
		r[i1][j2 + 1] -= d, r[i2 + 1][j2 + 1] += d;
	}

	rep(i, 1, m)
		rep(j, 1, n) {
			r[i][j] = r[i][j] + r[i - 1][j] + r[i][j - 1] - r[i - 1][j - 1];
			a[i][j] += r[i][j];
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}

	ans = -2e9;
	rep(i, 1, m - k + 1)
		rep(j, 1, n - k + 1)
			ans = max(ans, s[i + k - 1][j + k - 1] - s[i - 1][j + k - 1] - s[i + k - 1][j - 1] + s[i - 1][j - 1]);

	cout << ans << "\n";
	end_debug;
}