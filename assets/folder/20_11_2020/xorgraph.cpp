/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: xorgraph **/

#include <bits/stdc++.h>

#define task				"xorgraph"
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

int n, m, color[maxn], a[maxn];
vector<int> adj[maxn];
bool cnt[mask(20)];

void dfs(int u, int c) {
	color[u] = c;
	repa(v, adj[u]) {
		if(color[v] == 0)
			dfs(v, 3 - c);
		else if(color[u] == color[v]) {
			cout << "-1\n";
			exit(0);
		}
	}
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
//	fi(task".inp"), fo(task".out");
	
	cin >> n >> m;
	rep(i, 1, n)
		cin >> a[i];

	rep(i, 1, m) {
		int u, v;
		cin >> u >> v;
		if(a[u] != a[v])
			cnt[u ^ v] = true;
		else {
			adj[u].pb(v);
			adj[v].pb(u);
		}
	}

	rep(i, 1, n)
		if(color[i] == 0)
			dfs(i, 1);

	rep(i, 1, n)
	rep(i, 0, mask(20) - 1) {
		if(cnt[i] == false) {
			cout << i << " ";
			return 0;
		}
	}

		end_debug;
}