/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: CC **/

#include <bits/stdc++.h>

#define task				"CC"
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

set<int> lef, nadj[maxn];
bool visit[maxn];

int bfs(int z) {
	queue <int> q;
	q.push(z);
	int cnt = 0;

	while(q.size() > 0) {
		int u = q.front();
		q.pop();
		if(visit[u] == true)
			continue;

		cnt++;
		visit[u] = true;
		auto it = lef.begin();
		while(it != lef.end()) {
		    if(*it == u) {
                it++;
                continue;
		    }
		    auto nxt = it;
		    nxt++;
			auto chk = nadj[u].find(*it);
			if(chk == nadj[u].end()) {
				q.push(*it);
				lef.erase(it);
				it = nxt;
			}
			else it++;
		}
	}

	return cnt;
}

int n, m;
vector<int> ans;

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> n >> m;
	rep(i, 1, m) {
		int u, v;
		cin >> u >> v;
		nadj[u].insert(v);
		nadj[v].insert(u);
	}

	rep(i, 1, n)
		lef.insert(i);

	rep(i, 1, n)
		if(visit[i] == false) {
            lef.erase(i);
			ans.pb(bfs(i));
		}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	repa(u, ans)
		cout << u << " ";

	end_debug;
}
