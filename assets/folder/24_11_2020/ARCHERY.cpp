/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: ARCHERY **/

#include <bits/stdc++.h>

#define task				"ARCHERY"
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

const int maxn = 2e5 + 5;
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

#define int long long 

struct Point {
	int x = 0, y = 0;
};

struct Circle {
	Point C;
	int r = 0, id = 0;

	bool in(Point P) {
		/// (x - x0)^2 + (y - y0)^2 = U < R0
		ll xx = 1LL * (C.x - P.x) * (C.x - P.x);
		ll yy = 1LL * (C.y - P.y) * (C.y - P.y);
		return xx + yy < 1LL * r * r;
	}
};

Circle c[maxn];
int n, cnt;

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> n;
	rep(i, 1, n) {
		int id, u, v;
		cin >> id >> u >> v;
		if(id == 1) {
			Point Center;
			Center.x = u, Center.y = v;
			Circle T;
			T.C = Center;
			T.r = v;
			T.id = i;

			c[++cnt] = T;
		}
		else {
			int ans = -1;
			Point U; U.x = u, U.y = v;
			rep(j, 1, cnt) {
			    if(c[j].id == -1)
                    continue;
				if(c[j].in(U) == true) {
					ans = c[j].id;
					break;
				}
			}

			cout << ans << "\n";
            if(ans > 0) c[ans].id = -1;
		}
	}

	end_debug;
}
