/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: invspkers **/

#include <bits/stdc++.h>

#define task				"invspkers"
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

vector<int> rs(6);
pair<double, double> a[maxn], b[maxn];
int n;

void testcase() {
	cin >> n;
	rep(i, 0, n - 1)
		cin >> a[i].ft >> a[i].sd;
	rep(i, 0, n - 1)
		cin >> b[i].ft >> b[i].sd;

	vector<int> vt(n);
	rep(i, 0, n - 1)
		vt[i] = i;

	double minn = 1e9;
	do {
		double sum = 0;
		rep(i, 0, n - 1) {
			double xx = (a[i].ft - b[vt[i]].ft) * (a[i].ft - b[vt[i]].ft);
			double yy = (a[i].sd - b[vt[i]].sd) * (a[i].sd - b[vt[i]].sd);
			double dist = sqrt(xx + yy);
			sum += dist;
		}
		
		if(sum < minn) {
			minn = sum;
			rep(i, 0, n - 1)
				rs[i] = vt[i];
		}

	} while(next_permutation(vt.begin(), vt.end()));

	rep(i, 0, n - 1) {
		cout << 2 << "\n";
		cout << a[i].ft << " " << a[i].sd << "\n";
		cout << b[rs[i]].ft << " " << b[rs[i]].sd << "\n";
	}
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
//	fi(task".inp"), fo(task".out");
	
	int test; cin >> test;
	while(test--) {
		testcase();
	}

	end_debug;
}