/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: SP **/

#include <bits/stdc++.h>

#define task				"SP"
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

const int maxn = 1e6 + 5;
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

int F[maxn], n, k;
string s;
bool vis[maxn];
set<int> lef;

void bfs(int z) {
	queue<int> q;
	q.push(z);

	while(q.size() > 0) {
		int u = q.front();
		q.pop();
		if(vis[u] == true)
			continue;

		vis[u] = true;
		int L = u - min(k, u) + (k - min(k, u));
		int R = u + min(k, n - u) - (k - min(k, n - u));

		auto it = lef.lower_bound(L);
		if(*it > R) continue;

		bool even = (L % 2 == 0) ? true : false;

		while(it != lef.end()) {
			if(*it > R) break;

			if(*it == u) continue;
			if(even == true && *it % 2 == 0) continue;
			if(even == false && *it % 2 == 1) continue;

			auto nxt = it;
			nxt++;
			F[*it] = F[u] + 1;
			lef.erase(it);
			it = nxt;
		}
	}

}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
//	fi(task".inp"), fo(task".out");
	
	cin >> s;
	s = ' ' + s;
	n = s.size();
	cin >> k;

	int n0 = 0, n1 = 0;
	rep(i, 1, n)
		if(s[i] == '0') n0++;
		else n1++;

	rep(i, 1, n)
		lef.insert(i);
	bfs(n1);

	cout << F[0] << "\n";

	end_debug;
}