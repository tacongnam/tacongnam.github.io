/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: BUS **/

#include <bits/stdc++.h>

#define task				"BUS"
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

struct Waiting {
	int x, y, a;
} a[maxn];

vector<int> cx, cy;
vector<pii> row[maxn];
int m, n, k, dp[maxn], ans, b[maxn];

void Compress() {
	rep(i, 1, k)
		cx.pb(a[i].x);
	rep(i, 1, k)
		cy.pb(a[i].y);
	sort(cx.begin(), cx.end());
	sort(cy.begin(), cy.end());
	cx.resize(unique(cx.begin(), cx.end()) - cx.begin());
	cy.resize(unique(cy.begin(), cy.end()) - cy.begin());
	m = int(cx.size());
	n = int(cy.size());
	return ;
}

int Find(vector<int> &P, int val) {
	return lower_bound(P.begin(), P.end(), val) - P.begin() + 1;
}

int st[4 * maxn];
void upd(int id, int l, int r, int pos, int val) {
    if(pos < l || r < pos) return ;
    if(l == r) {
        st[id] = max(st[id], val);
        return ;
    }
    int mid = (l + r) / 2;
    upd(id * 2, l, mid, pos, val);
    upd(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if(r < u || v < l) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> m >> n >> k;
	rep(i, 1, k)
		cin >> a[i].x >> a[i].y >> a[i].a;

	Compress();

	rep(i, 1, k)
		row[Find(cx, a[i].x)].pb(mp(Find(cy, a[i].y), a[i].a));

	rep(i, 0, m)
		sort(row[i].begin(), row[i].end());

	rep(i, 1, m)
		repa(uu, row[i]) {
		    int u = uu.ft;
            b[u] = max(b[u], get(1, 1, n, 1, u) + uu.sd);
            upd(1, 1, n, u, b[u]);
            ans = max(ans, b[u]);
		}

	cout << ans << "\n";
	end_debug;
}
