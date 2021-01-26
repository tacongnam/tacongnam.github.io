/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: DWARFS **/

#include <bits/stdc++.h>

#define task				"DWARFS"
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

int n, u0, v0, ans, f[maxn], maxs[maxn], maxf[maxn];
bool in[maxn];
vector<int> adj[maxn], vt;
stack<int> st;

bool FindPath(int u, int p) {
	st.push(u);
	if(u == v0) {
		while(st.size() > 0) {
			in[st.top()] = true;
			vt.pb(st.top());
			st.pop();
		}
		return true;
	}

	repa(v, adj[u]) {
		if(v == p) continue;
		if(FindPath(v, u) == true)
			return true;
		st.pop();
	}
	return false;
}

void dfs(int u, int p) {
	int co = 0;
	f[u] = 1;
	repa(v, adj[u]) {
		if(v == p) continue;
		if(in[v] == true) {
			co = v;
			continue;
		}

		dfs(v, u);
		f[u] = max(f[u], f[v]);
	}
	return ;
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
//	fi(task".inp"), fo(task".out");
	
	cin >> n;
	rep(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	cin >> u0 >> v0;
	bool isok = FindPath(u0, u0);
	assert(isok == true);
	dfs(u0, u0);

	repd(i, vt.size(), 1)
		maxs[i] = max(maxs[i + 1], f[vt[i - 1]]);
	rep(i, 1, vt.size()) {
		maxf[i] = max(maxf[i - 1], f[vt[i - 1]]);
		ans = max(ans, maxf[i - 1] + maxs[i]);
	}

	cout << ans << "\n";

	end_debug;
}