/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: BOOTS **/

#include <bits/stdc++.h>

#define task				"BOOTS"
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

int n, m, a[maxn];
vector<pii> val, dp;
set<int> pos;
multiset<int> len;

void prepare() {
	rep(i, 2, n - 1)
		val.pb(mp(a[i], i));
    len.insert(n - 1);
    pos.insert(1), pos.insert(n);
	sort(val.begin(), val.end());

	rep(i, 0, val.size() - 1) {
		int j = i;

		while(i < val.size() - 1 && val[i].ft == val[i + 1].ft)
			i++;

		while(j <= i) {
            auto it1 = pos.upper_bound(val[j].sd);
            auto it2 = pos.lower_bound(val[j].sd);
            it2--;
            auto it3 = len.lower_bound(*it1 - *it2);
            len.erase(it3);
            len.insert(val[j].sd - *it2);
            len.insert(*it1 - val[j].sd);
            pos.insert(val[j].sd);
            j++;
		}

		auto it = len.end(); it--;
        dp.pb(mp(val[i].ft, *it));
	}
	sort(dp.begin(), dp.end());
	if(dp[0].ft != 0)
        dp.pb(mp(0, n - 1));
    sort(dp.begin(), dp.end());
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> n >> m;
	rep(i, 1, n)
		cin >> a[i];

    if(n <= 2) {
        rep(i, 1, m) {
            int u, v;
            cin >> u >> v;
            if(u > 0)
                cout << "0\n";
            else cout << "1\n";
        }
        return 0;
    }

	prepare();
	rep(i, 1, m) {
		int u, v;
		cin >> u >> v;
		int w = upper_bound(dp.begin(), dp.end(), mp(u, 2000000000)) - dp.begin() - 1;
		if(dp[w].sd > v)
			cout << 0 << "\n";
		else
			cout << 1 << "\n";
	}

	end_debug;
}
