/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
 
#include <bits/stdc++.h>
 
#define task				"PTREE"
#define fi(a)				freopen(a, "r", stdin);
#define fo(a)				freopen(a, "w", stdout);
#define rep(i, a, b)		for(auto (i) = (a); (i) <= (b); ++(i))
#define repd(i, a, b)		for(auto (i) = (a); (i) >= (b); --(i))
 
#define bit(a, i)			(((a) >> (i)) & 1)
#define mask(i)				(1LL << (i))
#define turn_off(a, i)		((a) &= ~mask(i))
 
#define pb					push_back
#define mp					make_pair
 
using namespace std;
 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#define	rand()				rng()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minqueue;
typedef priority_queue<pii> maxqueue;
 
const int maxn = 3e5 + 5;
const long long mod = 1e9 + 7;
const int base = 27;
const double pi = 3.14159265359;
 
int counterr = 0;
 
#define start_debug	cerr << "Debug status: \n"
#define debug(...) 	cerr << "[" << #__VA_ARGS__ << ": " << (__VA_ARGS__) << "] "
#define debuga(...)	cerr << "[" << #__VA_ARGS__ << ": "; counterr = 0; for(auto v : __VA_ARGS__){ counterr++, cerr << v; cerr << ((counterr != __VA_ARGS__.size()) ? "," : "");} cerr << "] "
#define end_debug	cerr << "\n"
 
/** End of template **/
/** Just enjoy my code **/
 
int n, c[maxn], dp[maxn], leaf;
vector<int> adj[maxn];
 
void dfs(int u) {
	for(int v : adj[u]) {
		dfs(v);
 
		if(c[u] == 1)
			dp[u] = min(dp[u], dp[v]);
		else
			dp[u] += dp[v];
	}
}
 
main() {
	start_debug;
 
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	fi(task".inp") fo(task".out")
 
	cin >> n;
 
	rep(i, 1, n)
		cin >> c[i];
 
	rep(i, 2, n) {
		int u; cin >> u;
		adj[u].pb(i);
	}
 
	rep(u, 1, n) {
		if(adj[u].size() == 0) {
			leaf++;
			c[u] = 1;
		}
		else {
			if(c[u] == 1)
				dp[u] = n + 2;
			else
				dp[u] = int(adj[u].size()) - 1;
		}
	}
 
	dfs(1);

	cout << leaf - dp[1];
 
	end_debug;
}