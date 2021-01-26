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

#define int 	long long

typedef long long ll;
typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> minqueue;
typedef priority_queue<pii> maxqueue;

const int maxn = 3e5 + 5;
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

int n, start, d, R[maxn], L[maxn], v[maxn], a[maxn], mpos[maxn];
pii t[maxn];

struct node {
	int cnt = 0;
	int sum = 0;

	node operator + (const node &P) const {
		node ans;
		ans.cnt = cnt + P.cnt;
		ans.sum = sum + P.sum;
		return ans;
	}
} st[4 * maxn];

void upd(int id, int l, int r, int pos, node val) {
	if(pos < l || r < pos) return ;
	if(l == r) {
		st[id] = val;
		return ;
	}
	int mid = (l + r) / 2;
	upd(id * 2, l, mid, pos, val);
	upd(id * 2 + 1, mid + 1, r, pos, val);
	st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int pos) { /// sum of 1 -> pos
	if(l == r) return st[id].sum;
	int mid = (l + r) / 2, ans = 0;

	if(st[id * 2].cnt < pos) {
		pos -= st[id * 2].cnt;
		ans += st[id * 2].sum;
		return ans + get(id * 2 + 1, mid + 1, r, pos);
	}
	else
		return get(id * 2, l, mid, pos);
}

int nnow = 0;
queue<pair<pii, pii>> q;
void DC(int l, int r, int LeftD, int RightD) {
	if(LeftD > RightD) return ;

	int pos = 0;
	int day = (LeftD + RightD) / 2;

    if(nnow < l)
        rep(i, nnow, l) {
            node P;
            P.cnt = 1, P.sum = a[i];
            upd(1, 1, n, mpos[i], P);
		}

	rep(i, l, r) {
		if(day - (i - start) <= 0) break;
		node P;
		P.cnt = 1, P.sum = a[i];
		upd(1, 1, n, mpos[i], P);
		int place = get(1, 1, n, day - (i - start));
		if(R[day] < place) {
			R[day] = place;
			v[day] = i - start;
			pos = i;
		}
	}

	nnow = r;

	node P;

    if(r == n) {
        rep(i, start, n)
            upd(1, 1, n, mpos[i], P);
        nnow = start;
    }

    q.push(mp(mp(l, pos), mp(LeftD, day)));
    q.push(mp(mp(pos, r), mp(day + 1, RightD)));

    pair<pii, pii> u = q.front();
    q.pop();
    DC(u.ft.ft, u.ft.sd, u.sd.ft, u.sd.sd);
}

void DCLeft(int l, int r, int LeftD, int RightD) {
	if(LeftD > RightD) return ;

	int pos = 0;
	int day = (LeftD + RightD) / 2;

    if(nnow > r)
        repd(i, nnow, r) {
            node P;
            P.cnt = 1, P.sum = a[i];
            upd(1, 1, n, mpos[i], P);
		}

	repd(i, r, l) {
		if(day - (start - i) <= 0) break;
		node P;
		P.cnt = 1, P.sum = a[i];
		upd(1, 1, n, mpos[i], P);
		int place = get(1, 1, n, day - (start - i));
		if(L[day] < place) {
			L[day] = place;
			pos = i;
		}
	}

	nnow = l;

	node P;

    if(r == start) {
        rep(i, 1, start)
            upd(1, 1, n, mpos[i], P);
        nnow = start;
    }

    q.push(mp(mp(pos, r), mp(LeftD, day - 1)));
    q.push(mp(mp(l, pos), mp(day + 1, RightD)));

    pair<pii, pii> u = q.front();
    q.pop();
    DCLeft(u.ft.ft, u.ft.sd, u.sd.ft, u.sd.sd);
}

void Sorting() {
	rep(i, 1, n)
		t[i] = mp(a[i], i);
	sort(t + 1, t + n + 1, greater<pii>());
	rep(i, 1, n)
		mpos[t[i].sd] = i;
}

int ans;
void Solve() {
	rep(i, 0, d)
		ans = max(ans, R[i] + L[max(0LL, d - i - v[i])]);
	cout << ans << "\n";
}

main() {
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> n >> start >> d;
	start++;
	rep(i, 1, n)
		cin >> a[i];

	Sorting();
	nnow = start;
	DC(start, n, 1, d);
	nnow = start;
	while(q.size() > 0)
        q.pop();
	DCLeft(1, start, 1, d);
	Solve();

	end_debug;
}

/*
20 19 50
522905331 790830264 523241603 725966799 261356140 268645912 738265913 54010376 116676841 695189422 159444778 515824928 532962684 50059433 103495964 171637792 17895220 193291079 875316298 812177630
*/
