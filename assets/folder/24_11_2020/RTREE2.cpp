/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: RTREE2 **/

#include <bits/stdc++.h>

#define task				"RTREE2"
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

int beg[maxn], en[maxn], d[maxn], pr[maxn][20], cnt;
vector<int> adj[maxn];

void dfs(int u, int p) {
	beg[u] = ++cnt;
	d[u] = d[p] + 1;
	pr[u][0] = p;
	rep(i, 1, 18)
		pr[u][i] = pr[pr[u][i - 1]][i - 1];
	repa(v, adj[u]) {
		if(v == p) continue;
		dfs(v, u);
	}
	en[u] = cnt;
}

int lca(int u, int v) {
	if(d[u] > d[v]) swap(u, v);
	repd(i, 18, 0)
		if((d[v] - d[u]) >= mask(i))
			v = pr[v][i];
	if(u == v) return u;
	repd(i, 18, 0)
		if(pr[u][i] != pr[v][i]) {
			u = pr[u][i];
			v = pr[v][i];
		}
	return pr[u][0];
}

int st[4 * maxn];
void upd(int id, int l, int r, int pos, int val) {
	if(pos < l || r < pos) return ;
	if(l == r) {
		st[id] += val;
		return ;
	}
	int mid = (l + r) / 2;
	upd(id * 2, l, mid, pos, val);
	upd(id * 2 + 1, mid + 1, r, pos, val);
	st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v) {
	if(r < u || v < l) return 0;
	if(u <= l && r <= v) return st[id];
	int mid = (l + r)/2;
	return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int n, m, u[maxn], v[maxn];
main() {
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> n >> m;
	rep(i, 1, n - 1) {
		cin >> u[i] >> v[i];
		adj[u[i]].pb(v[i]);
		adj[v[i]].pb(u[i]);
	}

	dfs(1, 1);
	rep(i, 1, n - 1)
		if(d[u[i]] < d[v[i]])
			swap(u[i], v[i]);

	while(m--) {
		int id;
		cin >> id;
		if(id == 1) {
			int up, vp;
			cin >> up >> vp;
			int l = lca(up, vp);
			upd(1, 1, n, beg[up], 1);
			upd(1, 1, n, beg[vp], 1);
			upd(1, 1, n, beg[l], -2);
		}
		else {
			int up; cin >> up;
			up = u[up];
			cout << get(1, 1, n, beg[up], en[up]) << "\n";
		}
	}

	end_debug;
}
