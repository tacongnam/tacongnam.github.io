/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: SEQMX **/

#include <bits/stdc++.h>

#define task				"SEQMX"
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
const double eps = 0.0000001;
const double pi = 3.14159265359;

int counterr = 0;

#define start_debug	cerr << "Debug status: \n"
#define debug(...) 	cerr << "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "] "
#define debuga(...)	cerr << "[" << #__VA_ARGS__ << ": "; counterr = 0; for(auto v : __VA_ARGS__){ counterr++, cerr << v; cerr << ((counterr != __VA_ARGS__.size()) ? "," : "");} cerr << "] "
#define end_debug	cerr << "\n"

/** End of template **/
/** Nếu bạn mất niềm tin vào cuộc sống, hãy đọc code này **/

int n, k;
double a[maxn], s[maxn];

bool check(double avr) {
	rep(i, 1, n)
		s[i] = s[i - 1] + a[i] - avr;

	double minn = 0;
	rep(i, k, n) {
		if(s[i] - minn >= 0)
			return true;
		minn = min(minn, s[i - k + 1]);
	}

	return false;
}

main() {
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
//	fi(task".inp"), fo(task".out");
	
	cin >> n >> k;
	rep(i, 1, n)
		cin >> a[i];

	double L = -1e5, R = 1e5;

	while(L <= R) {
		double mid = (L + R) / 2;
		if(check(mid) == true)
			L = mid + eps;
		else 
			R = mid - eps;
	}

	cout << fixed << setprecision(5) << L - eps << "\n";
}