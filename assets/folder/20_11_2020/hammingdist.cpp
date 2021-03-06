/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: HAMMINGDIST **/

#include <bits/stdc++.h>

#define task				"HAMMINGDIST"
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

int n, m, a[maxn], pp[260];
int cnt[257][257][9];

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

	fi(task".inp");

	cin >> n >> m;
	rep(i, 1, n)
		cin >> a[i];

    rep(i, 0, 256)
        pp[i] = __builtin_popcount(i);

	rep(i, 1, n) {
		int lef = a[i] - ((a[i] >> 8) << 8);
		int ft = a[i] >> 8;
		int bitx = pp[lef];
		rep(j, 0, m) {
		    if(i == n && j == 7)
                cerr << "";
			int ans = 0;
			rep(k, 0, mask(8) - 1) {
				int bit1 = pp[k ^ ft];
				if(bit1 > j) continue;
				int bit2 = j - bit1;
                if(bit2 > 8) continue;
				ans += cnt[k][lef][bit2];
			}
			cout << ans << " ";
		}
		cout << "\n";

		rep(j, 0, mask(8) - 1) {
            int diff = pp[lef ^ j];
            cnt[ft][j][diff]++;
		}

	}

	end_debug;
}
