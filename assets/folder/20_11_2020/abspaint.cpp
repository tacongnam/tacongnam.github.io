/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: abspaint **/

#include <bits/stdc++.h>

#define task				"abspaint"
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

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
//	fi(task".inp"), fo(task".out");
	
	cin >> n >> k;
	rep(i, 1, n) {
		cin >> c[i] >> r[i];
		cnt[c[i] - r[i] + 1]++, cnt[c[i] + r[i]]--;
		rbound[c[i] + r[i]].pb(r[i] / 2);
	}

	rep(i, 0, n) {
		if(i > 0)
			cnt[i] += cnt[i - 1];
		if(cnt[i] > 0)
			ban[i] = true;
	}

	rep(i, 2, n - 1) {
		int lim = min(10, i / 2 * 2);
		bool out = false;

		rep(mask, 0, mask(lim) - 1) {
			repd(j, lim, 0)
				if(bit(mask, j) == 0 && ban[i - j] == true) {
					out = true;
					break;
				}

			if(out == true)
				continue;

			int nmask = (mask << 1) % (mask(10));

			rep(nmsk, 0, mask(lim / 2) - 1) {
				repd(pos, lim / 2, 0) {
					if(bit(nmsk, pos) == 1) {
						repd(j, pos * 2, 0)
							nmask ^ 
					}
				}
			}
		}
}

	end_debug;
}