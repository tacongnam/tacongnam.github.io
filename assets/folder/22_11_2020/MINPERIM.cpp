/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: MINPERIM **/

#include <bits/stdc++.h>

#define task				"MINPERIM"
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

const int maxn = 1e2 + 5;
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
	int x, y;

	Point() {
		x = 0, y = 0;
	}

	double dist(Point A) {
		double xx = (double) (x - A.x) * (x - A.x);
		double yy = (double) (y - A.y) * (y - A.y);
		return sqrt(xx + yy);
	}

	ll ccw(Point A, Point B) {
		Point C = (*this);
		ll S = 1LL * (B.y - A.y) * (C.x - B.x);
		S -= 1LL * (B.x - A.x) * (C.y - B.y);
		return S;
	}
} blue[maxn], red[maxn];

int n, m;
double d[maxn][maxn];

void make_edge() {
	rep(i, 1, m) {
		rep(j, i + 1, m) {
			int sign = 0;
			rep(k, 1, n) {
				ll kk = blue[k].ccw(red[i], red[j]);
				if(kk == 0) {
                    sign = 0;
					break;
				}
				int fsign = (kk > 0) ? 1 : -1;
				if(sign == 0)
					sign = fsign;
				else if(sign != fsign) {
					sign = 0;
					break;
				}
			}

			if(sign < 0) {
				d[i][j] = red[i].dist(red[j]);
				d[j][i] = mod;
			}
			else if(sign > 0) {
				d[j][i] = red[j].dist(red[i]);
				d[i][j] = mod;
			}
			else d[i][j] = d[j][i] = mod;
		}
	}
	return ;
}

double floyd() {
	rep(i, 1, m) {
		rep(j, 1, m)
			cerr << d[i][j] << " ";
		cerr << "\n";
	}

	rep(k, 1, m)
		rep(i, 1, m)
			rep(j, 1, m)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	double ans = mod;
	rep(i, 1, m)
		rep(j, i + 1, m)
			ans = min(ans, d[i][j] + d[j][i]);
	return ans;
}

main() {
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> n;
	rep(i, 1, n)
		cin >> blue[i].x >> blue[i].y;
	cin >> m;
	rep(i, 1, m)
		cin >> red[i].x >> red[i].y;

	make_edge();
	cout << fixed << setprecision(2) << floyd();
	end_debug;
}

/*
1
0 2
4
-2 0
2 0
2 4
-2 4
*/
