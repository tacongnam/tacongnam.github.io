/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: XOR3 **/

#include <bits/stdc++.h>

#define task				"XOR3"
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

int dp[51][2][2][2][2][2][2];
int ans = 0;
bool ok_max = false, ok_min = false;
int a[4], b[4];
int calculate = 0;

void solve_max(int pos, bool ta[], bool tb[]) {
	if(pos == -1) {
		cout << ans << "\n";
		ok_max = true;
		dp[pos][ta[0]][tb[0]][ta[1]][tb[1]][ta[2]][tb[2]] = 1;
		return ;
	}

	if(dp[pos][ta[0]][tb[0]][ta[1]][tb[1]][ta[2]][tb[2]] == -1)
		return ;

	rep(i, 0, mask(3) - 1) {
		if(__builtin_popcount(i) % 2 == 0)
			continue;
		bool is_ok = true;
		bool nta[3] = {false}, ntb[3] = {false};
		rep(j, 0, 2) {
			int bc = bit(i, j);
			int bA = bit(a[j], pos);
			int bB = bit(b[j], pos);
			if(ta[j] == true && bc < bA)
				is_ok = false;
			if(tb[j] == true && bc > bB)
				is_ok = false;

			nta[j] = (bc == bA) ? ta[j] : false;
			ntb[j] = (bc == bB) ? tb[j] : false;
		}

		if(is_ok == true) {
			ans += mask(pos);
			solve_max(pos - 1, nta, ntb);
			ans -= mask(pos);
		}

		if(ok_max == true)
			break;
	}

	if(ok_max == false) {
		rep(i, 0, mask(3) - 1) {
			if(__builtin_popcount(i) % 2 == 1)
				continue;
			bool is_ok = true;
			bool nta[3] = {false}, ntb[3] = {false};
			rep(j, 0, 2) {
				int bc = bit(i, j);
				int bA = bit(a[j], pos);
				int bB = bit(b[j], pos);
				if(ta[j] == true && bc < bA)
					is_ok = false;
				if(tb[j] == true && bc > bB)
					is_ok = false;

				nta[j] = (bc == bA) ? ta[j] : false;
				ntb[j] = (bc == bB) ? tb[j] : false;
			}

			if(is_ok == true)
				solve_max(pos - 1, nta, ntb);

			if(ok_max == true)
				break;
		}
	}

	if(ok_max == true) {
		dp[pos][ta[0]][tb[0]][ta[1]][tb[1]][ta[2]][tb[2]] = 1;
		return ;
	}
	dp[pos][ta[0]][tb[0]][ta[1]][tb[1]][ta[2]][tb[2]] = -1;
}


void solve_min(int pos, bool ta[], bool tb[]) {
	if(pos == -1) {
		cout << ans << "\n";
		ok_min = true;
		dp[pos][ta[0]][tb[0]][ta[1]][tb[1]][ta[2]][tb[2]] = 1;
		return ;
	}

	if(dp[pos][ta[0]][tb[0]][ta[1]][tb[1]][ta[2]][tb[2]] == -1)
		return ;

	rep(i, 0, mask(3) - 1) {
		if(__builtin_popcount(i) % 2 == 1)
			continue;
		bool is_ok = true;
		bool nta[3] = {false}, ntb[3] = {false};
		rep(j, 0, 2) {
			int bc = bit(i, j);
			int bA = bit(a[j], pos);
			int bB = bit(b[j], pos);
			if(ta[j] == true && bc < bA)
				is_ok = false;
			if(tb[j] == true && bc > bB)
				is_ok = false;

			nta[j] = (bc == bA) ? ta[j] : false;
			ntb[j] = (bc == bB) ? tb[j] : false;
			calculate++;
		}

		if(is_ok == true)
			solve_min(pos - 1, nta, ntb);

		if(ok_min == true)
			break;
	}

	if(ok_min == false) {
		rep(i, 0, mask(3) - 1) {
			if(__builtin_popcount(i) % 2 == 0)
				continue;
			bool is_ok = true;
			bool nta[3] = {false}, ntb[3] = {false};
			rep(j, 0, 2) {
				int bc = bit(i, j);
				int bA = bit(a[j], pos);
				int bB = bit(b[j], pos);
				if(ta[j] == true && bc < bA)
					is_ok = false;
				if(tb[j] == true && bc > bB)
					is_ok = false;

				nta[j] = (bc == bA) ? ta[j] : false;
				ntb[j] = (bc == bB) ? tb[j] : false;
				calculate++;
			}

			if(is_ok == true) {
                ans += mask(pos);
				solve_min(pos - 1, nta, ntb);
                ans -= mask(pos);
			}

			if(ok_min == true)
				break;
		}
	}

	if(ok_min == true) {
		dp[pos][ta[0]][tb[0]][ta[1]][tb[1]][ta[2]][tb[2]] = 1;
		return ;
	}
	dp[pos][ta[0]][tb[0]][ta[1]][tb[1]][ta[2]][tb[2]] = -1;
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> a[0] >> b[0] >> a[1] >> b[1] >> a[2] >> b[2];
	bool f[3] = {true, true, true};
    solve_min(51, f, f);
//    cout << calculate << "\n";
	memset(dp, 0, sizeof(dp));
    solve_max(51, f, f);
	end_debug;
}
