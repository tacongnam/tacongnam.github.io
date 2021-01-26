/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: GIFT2 **/

#include <bits/stdc++.h>

#define task				"GIFT2"
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

int dp[18][3][2][2][2];
int n[18];

int calc(int pos, int re, bool tA, bool tB, bool tC) {
	if(pos == 0) {
		if(tA == false && tB == false && tC == false && re == 0)
			return 0;
		else return -mod;
	}

	if(dp[pos][re][tA][tB][tC] != -1)
		return dp[pos][re][tA][tB][tC];

	int best = -mod;
	int min2, min3;

	rep(ai, 0, 9) {
		if(tB == false) min2 = 0;
		else min2 = ai;
		rep(bi, min2, 9) {
			if(tC == false) min3 = 0;
			else min3 = bi;
			rep(ci, min3, 9)
				rep(nho2, 0, 2) {
					if((ai + bi + ci + nho2) / 10 != re)
						continue;
					if((ai + bi + ci + nho2) % 10 != n[pos])
						continue;
					bool nA = (ai > 0) ? 0 : tA;
					bool nB = (bi > ai) ? 0 : tB;
					bool nC = (ci > bi) ? 0 : tC;

					int tmp = ai + bi + ci + calc(pos - 1, nho2, nA, nB, nC);
					if(tmp < -1) tmp = -mod;
					best = max(best, tmp);
				}
		}
	}

	return dp[pos][re][tA][tB][tC] = best;
}

void testcase() {
	ll nn;
	cin >> nn;

	rep(i, 0, 17)
		n[i] = 0;
	int cnt = 0;
	while(nn > 0) {
		n[++cnt] = nn % 10;
		nn /= 10;
	}

	int ans = calc(cnt + 1, 0, true, true, true);
	if(ans == -mod)
		cout << "-1\n";
	else cout << ans << "\n";
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	fi(task".inp"), fo(task".out");

	int t; cin >> t;
	while(t--) {
		memset(dp, -1, sizeof(dp));
		testcase();
	}

	end_debug;
}
