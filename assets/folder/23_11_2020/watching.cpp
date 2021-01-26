/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: watching **/

#include <bits/stdc++.h>

#define task				"watching"
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

#define int long long

ll t, k, a[3][maxn], ans[3], ad[3], lim[3], now, cn = 1;

main() {
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> lim[1] >> lim[2] >> t >> k;
	rep(i, 1, lim[1])
		cin >> a[1][i];
	rep(i, 1, lim[2])
		cin >> a[2][i];

	rep(i, 1, 2) {
		a[i][0] = -k - 1;
		a[i][lim[i] + 1] = t + 1;
	}

	while(ad[1] <= lim[1] || ad[2] <= lim[2]) {
		while(a[cn][ad[cn]] < now)
			ad[cn]++;
		ans[cn] += min(a[cn][ad[cn]], t) - now;
		now = min(a[cn][ad[cn]], t);

		if(now >= t) break;
		
		cn = 3 - cn;
		while(a[cn][ad[cn]] + k < now)
			ad[cn]++;
		if(a[cn][ad[cn]] <= now && a[cn][ad[cn]] + k >= now)
			now = a[cn][ad[cn]] + k;
		if(now >= t) break;
	}

	cout << ans[1] << " " << ans[2];

	end_debug;
}

/*
1 1 10 3
2
1

1 1 10000000000000000 1000000000
2
9
*/