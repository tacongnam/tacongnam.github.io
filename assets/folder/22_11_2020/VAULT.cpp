/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: VAULT **/

#include <bits/stdc++.h>

#define task				"VAULT"
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

const int maxn = 4e3 + 5;
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
bool npr[5005];
vector<int> nprime;
void sang() {
	rep(i, 2, 5000) {
		if(npr[i] == false) {
			nprime.pb(i);
			rep(j, 2 * i, 5000 / i)
				npr[i * j] = true;
		}
	}
}

vector<int> fact(int x) {
	if(x == 1)
		return vector<int> (1, 1);
	vector<int> ans(0);
	repa(u, nprime) {
		if(x % u == 0)
			ans.pb(u);
		while(x % u == 0)
			x /= u;
	}
    if(x > 1)
        ans.pb(x);
	return ans;
}

int dp[maxn * maxn];
int a, b, l, ax, bx, abx;
int f(int x) {
	if(dp[x] >= 0) return dp[x];
	vector<int> prm = fact(x);
	int n = prm.size();
	dp[x] = 0;
	rep(i, 0, mask(n) - 1) {
		int cnt = __builtin_popcount(i), sign = 0;
		if(cnt % 2 == 1)
			sign = -1;
		else sign = 1;

		int mul = 1;
		rep(j, 0, n - 1)
			if(bit(i, j) == 1)
				mul *= prm[j];

		dp[x] += sign * (l / mul);
	}
	return dp[x];
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> a >> b;
	cin >> l;

	sang();
	memset(dp, -1, sizeof(dp));
	dp[0] = 1;
	dp[1] = l;

	rep(i, -a, b) {
		ax += f(i + a);
		bx += f(b - i);
		abx += f((i + a) * (b - i) / __gcd(i + a, b - i));
	}

	cout << l * (a + b + 1) - ax - bx + abx << "\n" << ax + bx - 2 * abx << "\n" << abx << "\n";

	end_debug;
}
