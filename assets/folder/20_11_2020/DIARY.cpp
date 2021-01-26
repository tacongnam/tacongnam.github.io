/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: DIARY **/

#include <bits/stdc++.h>

#define task				"DIARY"
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

const int maxn = 1e2 + 5;
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

int n, a[maxn], cost[maxn][maxn];
int dp[maxn][maxn];

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
//	fi(task".inp"), fo(task".out");
	
	cin >> n;
	rep(i, 1, n)
		cin >> a[i];

	rep(ft, 1, n)
		rep(sd, ft, n)
			rep(i, ft, sd)
				cost[ft][sd] += (a[i] == (i - ft));

	rep(i, 1, n)
		rep(k, 1, i) {
			dp[i][k] = 1e9;
			repd(j, i - 1, k - 1)
				dp[i][k] = min(dp[i][k], dp[j][k - 1] + cost[j][i - 1]);
		}

	rep(i, 1, n) {
		int ans = -1;
		rep(j, 1, n)
			ans = max(ans, dp[j][i]);
		cout << ans << '\n';
	}
	end_debug;
}