/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: SUMSQUARE **/

#include <bits/stdc++.h>

#define task				"SUMSQUARE"
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

ll n, m;

ll fadd(ll a, ll b, ll M) {
	return (((a + b / 2) % M + b / 2) % M + (b % 2 == 1)) % M;
}

ll fmul(ll a, ll b, ll M) {
	if(b == 0) return 0;
	if(b == 1) return a % M;
	ll X = fmul(a, b / 2, M);
	if(b % 2 == 0) return fadd(X, X, M);
	else return fadd(fadd(X, X, M), a, M);
}

ll mul(ll a, ll b, ll cons) {
	return fmul(a, b, m * cons);
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
//	fi(task".inp"), fo(task".out");
	
	cin >> n >> m;
	ll a1 = mul(4, mul(n, mul(n + 1, 2 * n + 1, 6), 6), 6) / 6;
	ll a2 = mul(4, mul(n, n + 1, 2), 2) / 2;
	ll a3 = (n + 1) % m;
	cout << (a1 + a2 + a3) % m;
	end_debug;
}