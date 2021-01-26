/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: LAMPS **/

#include <bits/stdc++.h>

#define task				"LAMPS"
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

#define sz(a)		(int(a.size()))

struct flow {
	int u, v, f, c, id;
};

vector<int> adj[maxn];
vector<flow> edge;
bool inq[maxn], vi[maxn];
int s, t, p[maxn];
queue<int> q;

void add(int u, int v, int c) {
	edge.pb({u, v, 0, c, sz(edge) + 1});
	adj[u].pb(sz(edge) - 1);
	edge.pb({v, u, 0, 0, sz(edge) - 1});
	adj[v].pb(sz(edge) - 1);
}

bool bfs() {
	rep(i, s, t) {
		p[i] = -1;
		inq[i] = false;
	}

	q.push(s);

	while(sz(q) > 0) {
		int u = q.front();
		q.pop();
		inq[u] = false;
		repa(id, adj[u]) {
			flow v = edge[id];
			if(p[v.v] == -1 && v.f < v.c) {
				p[v.v] = id;
				if(inq[v.v] == false) {
					q.push(v.v);
					inq[v.v] = true;
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
		int id = p[u];
		flow v = edge[id];
		delta = min(delta, v.c - v.f);
		u = v.u;
	}

	u = t;
	while(u != s) {
        int id = p[u];
		flow &v = edge[id];
		v.f += delta;
		edge[v.id].f -= delta;
		u = v.u;
	}

    maxflow += delta;
	return ;
}

int Solve() {
	maxflow = 0;
	while(bfs() == true)
		IncFlow();
	return maxflow;
}

int n, m, k;
int cycle[maxn], color[maxn];
vector<pii> st, ke[maxn];
int count_cycle[maxn], cnt;

void dfs(int u, int p) {
	vi[u] = true;
	repa(v, ke[u]) {
		if(v.ft == p) continue;
		if(vi[v.ft] == false) {
			st.pb(mp(u, v.sd));
			inq[u] = true;
			dfs(v.ft, u);
			st.pop_back();
			inq[u] = false;
		}
		else if(inq[v.ft] == true) {
			++cnt;
			st.pb(mp(u, v.sd));
			repd(i, sz(st) - 1, 0) {
			    pii _v = st[i];
				cycle[_v.sd] = cnt;
				count_cycle[cnt]++;
				if(_v.ft == v.ft)
					break;
			}
			st.pop_back();
		}
	}
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> n >> m;
	rep(i, 1, m) {
		int u, v;
		cin >> u >> v >> color[i];
		ke[u].pb(mp(v, i));
		ke[v].pb(mp(u, i));
	}

	dfs(1, 1);
	rep(i, 1, m)
		if(cycle[i] == 0) {
			cycle[i] = ++cnt;
			count_cycle[cnt]++;
		}

	s = 0, t = 3 * m + 1;

	rep(i, 1, cnt)
		add(s, i, (count_cycle[i] == 1) ? 1 : (count_cycle[i] - 1));

	rep(i, 1, m)
		add(cycle[i], i + m, 1);

	rep(i, 1, m) {
		add(i + m, color[i] + m + m, 1);
		add(i + m + m, t, 1);
	}

	cout << Solve();

	end_debug;
}

/*
8 8
1 2 1
2 3 2
3 4 5
4 5 7
5 6 2
6 7 3
7 8 4
8 4 6
*/