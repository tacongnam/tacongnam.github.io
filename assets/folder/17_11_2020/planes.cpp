/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: PLANES **/

#include <bits/stdc++.h>

#define task				"PLANES"
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

queue<int> q;
bool inq[maxn];
int p[maxn], f[maxn][maxn], c[maxn][maxn];
int s, t, a[maxn], b[maxn], z[maxn];
int n, m, k, cnt, maxflow;
vector<int> adj[maxn];

bool bfs() {
	rep(i, s, t)
		p[i] = -1;
	p[s] = 0;
	q.push(s);
	while(q.size() > 0) {
		int u = q.front(); q.pop();
		inq[u] = false;
		repa(v, adj[u]) {
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
}

void Checkcnt() {
	s = 0, t = n + m + 1;

	rep(i, 1, n) {
		if(z[i] == 0) continue;
		adj[s].pb(i);
		adj[i].pb(s);
		c[s][i] = 1;
		cnt++;
	}

	rep(i, 1, n) {
		rep(j, a[i], b[i]) {
			adj[i].pb(j + n);
			adj[j + n].pb(i);
			c[i][j + n] = 1;
		}
	}

	rep(i, n + 1, n + m) {
		adj[i].pb(t);
		adj[t].pb(i);
		c[i][t] = k;
	}

	maxflow = 0;
	while(bfs() == true)
		IncFlow();

	if(maxflow != cnt) {
		cout << 0;
		return ;
	}

	rep(i, 1, n) {
		if(z[i] == 1) continue;
		adj[s].pb(i);
		adj[i].pb(s);
		c[s][i] = 1;
	}

	while(bfs() == true)
		IncFlow();

	cout << maxflow << "\n";
	rep(i, 1, n) {
		rep(j, n + 1, n + m + 1) {
			if(j == n + m + 1) {
				cout << 0 << " ";
				if(z[i] == 1) exit(1);
			}
			else if(c[i][j] > 0 && f[i][j] == c[i][j]) {
				cout << j - n << " ";
				break;
			}
		}
	}
}

void input() {
	cin >> n >> m >> k;
	rep(i, 1, n)
		cin >> a[i] >> b[i] >> z[i];
	return ;
}
main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
//	fi(task".inp"), fo(task".out");
	
	input();
	Checkcnt();

	end_debug;
}