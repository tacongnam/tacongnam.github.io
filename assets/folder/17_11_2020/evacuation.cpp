/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: EVACUATION **/

#include <bits/stdc++.h>

#define task				"EVACUATION"
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
typedef pair<long long, int> pli;
typedef priority_queue<pli, vector<pli>, greater<pli>> minqueue;
typedef priority_queue<pii> maxqueue;

const int maxn = 2e3 + 5;
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

int n, m, k;
vector<pair<int, ll>> adj[maxn];
pii tunnel[20];

void input() {
	cin >> n >> m >> k;
	rep(i, 1, m) {
		int a, b, z;
		cin >> a >> b >> z;
		adj[a].pb(mp(b, z));
		adj[b].pb(mp(a, z));
	}
	rep(i, 1, k) {
		int x, y;
		cin >> x >> y;
		tunnel[i] = mp(x, y);
	}
	return ;
}

minqueue pq;
ll d[20][maxn];

void dijkstra(int id) {
	int s = tunnel[id].ft;
	rep(i, 1, n)
		d[id][i] = 1e18;
	d[id][s] = 0;
	pq.push(mp(0, s));

	while(pq.size() > 0) {
		pair<ll, int> u = pq.top();
		pq.pop();
		if(u.ft != d[id][u.sd])
			continue;
		repa(v, adj[u.sd]) {
			if(d[id][v.ft] > u.ft + v.sd) {
				d[id][v.ft] = u.ft + v.sd;
				pq.push(mp(d[id][v.ft], v.ft));
			}
		}
	}

	return ;
}

int p[maxn], f[maxn][maxn], c[maxn][maxn];
vector<int> edge[maxn];
int s, t;
queue<int> q;
bool inq[maxn];

bool bfs() {
	rep(i, s, t)
		p[i] = -1;
	q.push(s);
	p[s] = 0;
	while(q.size() > 0) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		repa(v, edge[u]) {
			if(p[v] == -1 && f[u][v] < c[u][v]) {
				p[v] = u;
				if(inq[v] == false) {
					inq[v] = true;
					q.push(v);
				}
			}
		}
	}

	return p[t] != -1;
}

int maxflow;
void IncFlow() {
	int u = t, delta = 1e9;
	while(u != s) {
		int v = p[u];
		delta = min(delta, c[v][u] - f[v][u]);
		u = v;
	}

	u = t;
	while(u != s) {
		int v = p[u];
		f[v][u] += delta;
		f[u][v] -= delta;
		u = v;
	}

	maxflow += delta;
	return ;
}

bool ft_time = false;
bool check(ll mid) {
	rep(i, s, t)
		rep(j, s, t)
			c[i][j] = f[i][j] = 0;

	s = 0, t = n + k + 1;
	rep(i, 1, n) {
		if(ft_time == false) {
			edge[s].pb(i);
			edge[i].pb(s);
		}
		c[s][i] = 1;
	}

	rep(i, 1, n)
		rep(j, 1, k) {
			if(ft_time == false) {
				edge[j + n].pb(i);
				edge[i].pb(j + n);
			}

			if(d[j][i] <= mid)
				c[i][j + n] = 1;
		}
	
	rep(i, 1, k) {
		if(ft_time == false) {
			edge[i + n].pb(t);
			edge[t].pb(i + n);
		}

		c[i + n][t] = tunnel[i].sd;
	}

	maxflow = 0;
	while(bfs() == true)
		IncFlow();

	ft_time = true;
	return maxflow >= n;
}

void solve() {
	rep(i, 1, k)
		dijkstra(i);

	ll L = 0, R = 1e12;
	while(L < R) {
		ll mid = (L + R) / 2;
		if(check(mid) == true)
			R = mid;
		else L = mid + 1;
	}
	cout << L << "\n";
	return ;
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
//	fi(task".inp"), fo(task".out");
	
	input();
	solve();

	end_debug;
}