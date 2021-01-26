/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: LRXOR **/
/** Tag: Trie **/

#include <bits/stdc++.h>

#define task				"LRXOR"
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

struct Trie{
	Trie *child[2];

	Trie() {
		rep(i, 0, 1)
			child[i] = nullptr;
	}
} *root = new Trie();

void add(int X) {
	Trie *u = root;
	repd(i, 31, 0) {
		int b = bit(X, i);
		if(u->child[b] == nullptr)
			u->child[b] = new Trie();
		u = u->child[b];
	}
}

int get_max(int xr) {
	Trie *u = root;
	int ans = 0;
	repd(i, 31, 0) {
		int b = bit(xr, i);
		if(u->child[1 - b] != nullptr) {
			ans += mask(i);
			u = u->child[1 - b];
		}
		else {
			if(u->child[b] != nullptr)
				u = u->child[b];
			else break;
		}
	}
	return ans;
}

int n, a[maxn], x[maxn], res;

void testcase() {
	*root = Trie();

	cin >> n;
	rep(i, 1, n) {
		cin >> a[i];
		x[i] = x[i - 1] ^ a[i];
	}

	add(x[n]);
	res = 0;
	repd(i, n - 1, 0) {
		res = max(res, get_max(x[i]));
		add(x[i]);
	}

	cout << res << "\n";
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	fi(task".inp"), fo(task".out");
	
	int t; cin >> t;
	while(t--) {
		testcase();
	}

	end_debug;
}