/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: potential **/

#include <bits/stdc++.h>

#define task				"potential"
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

const int maxn = 300 + 5;
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

	bool operator < (const Point &P) {
		if(x == P.x) return y < P.y;
		return x < P.x;
	}

	ll ccw(Point A, Point B) {
		Point C = (*this);
		ll S = 1LL * (B.y - A.y) * (C.x - B.x);
		S -= 1LL * (B.x - A.x) * (C.y - B.y);
		return S;
	}

	bool isUnder(Point A, Point B) {
	    return (*this).ccw(A, B) > 0;
	}
} a[maxn];

int n, cnt[maxn][maxn], ans[maxn];

main() {
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> n;
	rep(i, 1, n)
		cin >> a[i].x >> a[i].y;

    sort(a + 1, a + n + 1);
//    cout << a[3].isUnder(a[1], a[4]);

	rep(i, 1, n)
		rep(j, i + 2, n) {
		    if(i == 2 && j == 4)
                cerr << "";
			rep(k, i + 1, j - 1)
                cnt[i][j] += a[k].isUnder(a[i], a[j]);
		}

	rep(i, 1, n)
		rep(j, i + 2, n)
			rep(k, i + 1, j - 1) {
                int co = 0;
                if(a[k].isUnder(a[i], a[j]) == false)
                    co = cnt[i][k] + cnt[k][j] - cnt[i][j];
                else
                    co = cnt[i][j] - cnt[i][k] - cnt[k][j] - 1;
                ans[co]++;
			}

	rep(i, 0, n - 3)
		cout << ans[i] << "\n";
	end_debug;
}
