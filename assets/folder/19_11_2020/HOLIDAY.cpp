/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: HOLIDAY **/

#include <bits/stdc++.h>

#define task				"HOLIDAY"
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
typedef pair<int, long long> pil;
typedef priority_queue<pil, vector<pil>, greater<pil>> minqueue;
typedef priority_queue<pil> maxqueue;

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

struct SegTree {
	vector<pil> st;

	SegTree(int sz) {
		st.resize(4 * sz + 5);
	}

	void init(int id, int l, int r) {
		st[id].ft = st[id].sd = 0;
		if(l == r)
			return ;
		int mid = (l + r) / 2;
		init(id * 2, l, mid);
		init(id * 2 + 1, mid + 1, r);
		return ;
	}

	void upd(int id, int l, int r, int pos, pil val) {
		if(pos < l || r < pos)
			return ;
		if(l == r) {
			st[id] = val;
			return ;
		}
		int mid = (l + r) / 2;
		upd(id * 2, l, mid, pos, val);
		upd(id * 2 + 1, mid + 1, r, pos, val);
		st[id] = mp(st[id * 2].ft + st[id * 2 + 1].ft, st[id * 2].sd + st[id * 2 + 1].sd);
		return ;
	}

	ll get(int id, int l, int r, int val) {
		if(l == r)
			return st[id].sd;

		int mid = (l + r) / 2;
		ll ans = 0;

		if(st[id * 2].ft < val) {
			val -= st[id * 2].ft;
			ans += st[id * 2].sd;
			return ans + get(id * 2 + 1, mid + 1, r, val);
		}
		else
			return get(id * 2, l, mid, val);
	}
} S = SegTree(0);

struct query {
	int l, r, U, V;
	bool ended;
};

const int maxL = 2 * maxn + maxn / 2 + 2;

queue<query> q;
ll Left[maxL], Right[maxL], a[maxn];
int pos[maxn], v[maxL];
int n, start, d;

int nw = 0;

void CalcLeft(int l, int r, int U, int V, bool ended) {
	int day = (U + V) / 2, tk = -1;
	if(U > V || Left[day] > -1) {
	    if(ended == true)
            S.init(1, 1, n);

        if(q.size() > 0) {
            query top = q.front();
            q.pop();
            CalcLeft(top.l, top.r, top.U, top.V, top.ended);
        }
        return;
	}

	while(nw > r)
        S.upd(1, 1, n, pos[nw], mp(1, a[nw])), nw--;

	repd(i, r, l) {
		int choose = day - (start - 1 - i);
        if(choose <= 0) continue;
		S.upd(1, 1, n, pos[i], mp(1, a[i]));

		ll best = S.get(1, 1, n, min(n, choose));

		if(Left[day] < best) {
            Left[day] = best;
			tk = i;
		}
	}
	nw = l;

	if(ended == true) {
		S.init(1, 1, n);
		nw = start - 1;
	}

	query ft = {(tk == -1) ? l : tk, r, U, day - 1, false};
	query sd = {l, (tk == -1) ? r : tk, day + 1, V, ended};
	q.push(ft), q.push(sd);

	if(q.size() > 0) {
        query top = q.front();
        q.pop();
        CalcLeft(top.l, top.r, top.U, top.V, top.ended);
	}
	return ;
}

void CalcRight(int l, int r, int U, int V, bool ended) {
	int day = (U + V) / 2, tk = -1;
	if(U > V || Right[day] > -1) {
        if(ended == true)
            S.init(1, 1, n);

        if(q.size() > 0) {
            query top = q.front();
            q.pop();
            CalcRight(top.l, top.r, top.U, top.V, top.ended);
        }
        return;
	}

	while(nw < l)
        S.upd(1, 1, n, pos[nw], mp(1, a[nw])), nw++;

	rep(i, l, r) {
		int choose = day - (i - start);
        if(choose <= 0) continue;
		S.upd(1, 1, n, pos[i], mp(1, a[i]));

		ll best = S.get(1, 1, n, min(n, choose));

		if(Right[day] < best) {
			Right[day] = best;
			tk = i;
			v[day] = i - start;
		}
	}

	nw = r;

	if(ended == true) {
		S.init(1, 1, n);
		nw = start;
	}

	query ft = {l, (tk == -1) ? r : tk, U, day - 1, false};
	query sd = {(tk == -1) ? l : tk, r, day + 1, V, ended};
	q.push(ft), q.push(sd);

    if(q.size() > 0) {
        query top = q.front();
        q.pop();
        CalcRight(top.l, top.r, top.U, top.V, top.ended);
    }
	return ;
}

vector<pil> tourist;
void Compress() {
	rep(i, 1, n)
		tourist.pb(mp(a[i], i));
	sort(tourist.begin(), tourist.end(), greater<pil>());
	int cnt = 0;
	repa(u, tourist)
		pos[u.sd] = ++cnt;
	tourist.clear();
	return ;
}

main() {
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> n >> start >> d;
	start++;
	S = SegTree(n);
	ll s = 0;
	rep(i, 1, n)
		cin >> a[i];
	Compress();

    rep(i, 1, d)
        Left[i] = Right[i] = -1;
	S.init(1, 1, n);
	nw = start - 1;
	CalcLeft(1, start - 1, 1, d - 1, true);
	while(q.size() > 0)
		q.pop();
	S.init(1, 1, n);
	nw = start;
	CalcRight(start, n, 1, d, true);

    ll ans = -1;
	rep(i, 1, d) {
	    if(Right[i] == -1 || Left[max(0, d - i - v[i] - 1)] == -1)
            continue;
		ans = max(ans, Right[i] + Left[max(0, d - i - v[i] - 1)]);
	}
	cout << ans << "\n";

	end_debug;
}

/**
20 19 50
972612261 856587041 750277994 689962571 649794888 595278434 577383213 527323780 468968254 417055110 371641672 349099082 259972417 211748900 123858939 87065197 40111108 25617767 18419694 16599942
**/

/**
10 9 21
1000000000 1000000000 1000000000 1000000000 1000000000
1000000000 1000000000 1000000000 1000000000 1000000000
**/

/**
20 0 50
398635416 750381019 537306117 954586563 806620158 206792153 244810228 548662558 267271899 556649514 739694305 790177230 199996131 115452261 368660382 461352272 384098173 106926294 367879002 500775015
**/
