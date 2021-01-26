/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: CLOPAIR **/

#include <bits/stdc++.h>

#define task				"CLOPAIR"
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

struct Point {
	double x, y;
	int id;

	bool operator < (const Point &P) {
		return x < P.x;
	}

	double dist(Point A) {
		return sqrt(1LL * (x - A.x) * (x - A.x) + 1LL * (y - A.y) * (y - A.y));
	}
} a[maxn];

bool cY(Point A, Point B) {
	return A.y < B.y;
}

int n;

pair<pii, double> merge2(int L, int R, double mind) {
	Point d2[R - L + 2];
	int mid = (L + R) / 2, cnt = 0;
	
	rep(i, L, R)
		if(abs(a[i].x - a[mid].x) <= mind)
			d2[++cnt] = a[i];
	sort(d2 + 1, d2 + cnt + 1, cY);

	pii p; double res = mind;

	rep(i, 1, cnt)
		rep(j, i + 1, cnt) {
		    if(abs(d2[i].y - d2[j].y) > mind)
                break;
			if(d2[i].dist(d2[j]) <= res) {
				p = mp(d2[i].id, d2[j].id);
				res = d2[i].dist(d2[j]);
			}
		}

	return mp(p, res);
}

pair<pii, double> bruteforce(int L, int R) {
	pii p = mp(n, n);
	double dist = 1e18;

	rep(i, L, R)
		rep(j, i + 1, R)
			if(dist > a[i].dist(a[j])) {
				dist = a[i].dist(a[j]);
				p = mp(a[i].id, a[j].id);
			}

	return mp(p, dist);
}

pair<pii, double> solve(int L, int R) {
	if(L > R) return mp(mp(n, n), 1e18);
	if(R - L + 1 <= 3) return bruteforce(L, R);

	pair<pii, double> m1 = solve(L, (L + R) / 2);
	pair<pii, double> m2 = solve((L + R) / 2 + 1, R);
	double mind = min(m1.sd, m2.sd);
	pair<pii, double> m12 = merge2(L, R, mind);

	if(m12.sd < mind)
		return m12;
	else {
		if(m1.sd > m2.sd)
			return m2;
		else return m1;
	}
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

		cin >> n;

		rep(i, 1, n) {
		    cin >> a[i].x >> a[i].y;
			a[i].id = i - 1;
		}

		sort(a + 1, a + n + 1);
		pair<pii, double> ans = solve(1, n);
		cout << min(ans.ft.ft, ans.ft.sd) << " " << max(ans.ft.ft, ans.ft.sd) << " ";
		cout << fixed << setprecision(6) << ans.sd << "\n";


	end_debug;
}
