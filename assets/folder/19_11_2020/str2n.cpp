/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: str2n **/

#include <bits/stdc++.h>

#define task				"str2n"
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

const int maxn = 2e6 + 5;
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

struct Trie{
	Trie *child[26];
	vector<int> q;

	Trie() {
		rep(i, 0, 25)
			child[i] = nullptr;
	}
} *root = new Trie();

void add(string X, int id) {
	Trie *u = root;
	rep(i, 0, int(X.size()) - 1) {
		int b = int(X[i] - 'a');
		if(u->child[b] == nullptr)
			u->child[b] = new Trie();
		u = u->child[b];
	}

	u->q.pb(id);
}

stack<int> ss;
vector<pii> ans;
string s;
int n;

void dfs(Trie *u) {
	int fin = 0;
	repa(v, u->q)
		ss.push(v);

	rep(i, 0, 25) {
		if(u->child[i] != nullptr)
			dfs(u->child[i]);
	}

	repd(i, int((u->q).size() - 1), 0) {
		if(ss.size() > 0 && (u->q)[i] == ss.top()) {
			int a = ss.top(); ss.pop();
			int b = ss.top(); ss.pop();
			ans.pb(mp(a, b));
		}
	}

	return ;
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	fi(task".inp"), fo(task".out");

	cin >> n;
	rep(i, 1, 2 * n) {
		cin >> s;
		add(s, i);
	}
	dfs(root);

	repa(u, ans)
		cout << u.ft << " " << u.sd << "\n";

	end_debug;
}
