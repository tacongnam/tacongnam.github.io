/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: MPATH **/

#include <bits/stdc++.h>

#define task				"MPATH"
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

const int maxn = 2e5 + 5;
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

int m, u[maxn], v[maxn];
vector<int> vt, adj[maxn];
int f[maxn], r[maxn], ans;

int Find(int val) {
	return lower_bound(vt.begin(), vt.end(), val) - vt.begin();
}

void Compress() {
	rep(i, 1, m)
		vt.pb(u[i]), vt.pb(v[i]);
	sort(vt.begin(), vt.end());
	vt.resize(unique(vt.begin(), vt.end()) - vt.begin());

	rep(i, 1, m) {
		u[i] = Find(u[i]);
		v[i] = Find(v[i]);
	}
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	fi(task".inp"), fo(task".out");
	
	cin >> m;
	rep(i, 1, m)
		cin >> u[i] >> v[i];
	
	Compress();

	rep(i, 1, m) {
		if(u[i] == v[i]) r[u[i]]++;
		else {
			if(u[i] < v[i]) swap(u[i], v[i]);
			adj[u[i]].pb(v[i]);
		}
	}

	repd(i, 2 * m, 0) {
		f[i] += r[i];
		repa(v, adj[i])
			f[v] = max(f[v], f[i] + 1);
		ans = max(ans, f[i]);
	}

	cout << ans << "\n";

	end_debug;
}