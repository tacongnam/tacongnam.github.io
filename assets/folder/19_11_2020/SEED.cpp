/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: SEED **/

#include <bits/stdc++.h>

#define task				"SEED"
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

int cnt;

struct Trie{
	Trie *child[2];
	int id;

	Trie() {
		rep(i, 0, 1)
			child[i] = nullptr;
		id = ++cnt;
	}
} *root = new Trie();

void add(string X) {
	Trie *u = root;
	rep(i, 0, int(X.size()) - 1) {
		int b = int(X[i] - '0');
		if(u->child[b] == nullptr)
			u->child[b] = new Trie();
		u = u->child[b];
	}
}

bool Search(string X) {
	Trie *u = root;
	rep(i, 0, int(X.size()) - 1) {
		int b = int(X[i] - '0');
		if(u->child[b] == nullptr)
			return false;
		u = u->child[b];
	}
	return true;
}

int check(string now) {
	repd(i, int(now.size()) - 1, 1) {
		string p = substr()
	}
}

void dfs(Trie *u, Trie *p, int du, int dp) {
	// f[u][0] and f[u][1]
	f[u->id][du] = f[p->id][dp];
	
	// f[u->id][1 - du];
	now += char(1 - du + '0');
	f[u->id][1 - du] = check(now);
}

void solve() {
	
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
//	fi(task".inp"), fo(task".out");
	
	cout << "Hello world";

	end_debug;
}