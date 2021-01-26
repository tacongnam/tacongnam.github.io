/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: ASTR **/

#include <bits/stdc++.h>

#define task				"ASTR"
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
const long long mod = 111539786;
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

string t, p, s;
int f[maxn], n, m;

void sufpre() {
	rep(i, 1, m) {
		t[i] = (p[i] == '0') ? '1' : '0';
		repd(ft, i, 1) {
			rep(j, ft, i + 1) {
				if(j == i + 1)
					f[i] = max(f[i], i - ft + 1);
				if(t[j] != p[j - ft + 1])
					break;
			}
		}
		t[i] = p[i];
	}

	rep(i, 1, m)
		debug(f[i]);
}

int dp[maxn][12], ans;
void solve() {
	dp[0][0] = 1;

	rep(i, 0, n)
		rep(j, 0, m - 1) {
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
			dp[i + 1][f[j + 1]] = (dp[i + 1][f[j + 1]] + dp[i][j]) % mod;
		}

	rep(i, 0, m - 1)
		ans = (ans + dp[n][i]) % mod;
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> n >> p;
	m = p.size();
	p = ' ' + p;
	sufpre();
	solve();
	cout << ans << "\n";

	end_debug;
}
