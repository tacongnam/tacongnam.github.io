/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: sflip **/

#include <bits/stdc++.h>

#define task				"sflip"
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

int n, a[maxn], b[maxn];
int dp[mask(18)][20];

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> n;
	rep(i, 0, n - 1)
		cin >> a[i];
	rep(i, 0, n - 1)
		cin >> b[i];

	rep(i, 1, mask(n) - 1)
		rep(j, 0, n)
			dp[i][j] = 1e9;

	rep(i, 0, n - 1)
		dp[mask(i)][i] = i;

	rep(i, 1, mask(n) - 2) {
		int nbit = __builtin_popcount(i) - 1;
		vector<int> n0, n1;
		rep(j, 0, n - 1) {
			if(bit(i, j) == 0)
				n0.pb(j);
			else
				n1.pb(j);
		}

		repa(i1, n1) {
			int num1 = ((nbit - i1) % 2 == 0) ? a[i1] : b[i1];
			repa(i0, n0) {
				int num0 = ((nbit + 1 - i0) % 2 == 0) ? a[i0] : b[i0];
				if(num1 > num0)
					continue;
                int rem = 0;
                repa(a1, n1)
                    if(a1 > i0)
                        rem++;
				dp[i + mask(i0)][i0] = min(dp[i + mask(i0)][i0], dp[i][i1] + abs(nbit + 1 - i0 - rem));
			}
		}
	}

	int ans = 1e9;
	rep(i, 0, n - 1)
		ans = min(ans, dp[mask(n) - 1][i]);

	cout << ((ans == 1e9) ? -1 : ans);

	end_debug;
}
