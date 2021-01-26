/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: CARD **/

#include <bits/stdc++.h>

#define task				"CARD"
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

int c, n, b[maxn * 4], res;
vector<int> perm;
vector<pii> adj[5];

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> c >> n;
	rep(i, 1, n * c) {
		int u, v; cin >> u >> v;
		adj[u].pb(mp(v, i));
	}

	rep(i, 1, c) {
		sort(adj[i].begin(), adj[i].end());
		perm.pb(i);
	}


	do {
		rep(i, 0, c - 1)
			rep(j, 0, n - 1) {
				int id = n * i + j + 1;
				b[id] = adj[perm[i]][j].sd;
			}

		vector<int> lis(0);
		rep(i, 1, n * c) {
			int pos = lower_bound(lis.begin(), lis.end(), b[i]) - lis.begin();
			if(pos == lis.size())
				lis.pb(b[i]);
			else lis[pos] = b[i];
		}

		res = max(res, int(lis.size()));
	} while(next_permutation(perm.begin(), perm.end()));

	cout << n * c - res << "\n";

	end_debug;
}
