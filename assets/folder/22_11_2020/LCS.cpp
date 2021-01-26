/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: LCS **/

#include <bits/stdc++.h>

#define task				"LCS"
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

vector<vector<ll>> hsh;
string s[maxn];
ll po[maxn];
int n;

ll gethash(int L, int R, int id) {
	return (hsh[id][R] - hsh[id][L - 1] * (R - L + 1) + mod * mod) % mod;
}

map<ll, pii> mpp;
bool check(int mid) {
	rep(i, 1, n) {
		rep(j, mid, int(s[i].size()) - 1) {
			ll X = gethash(j - mid + 1, mid, i);
			auto it = mpp.find(X);
			if(it == mpp.end())
				mpp.insert(mp(X, mp(1, i)));
			else {
				if(it->sd.sd == i) continue;
				else {
					mpp[X] = mp(it->sd.ft + 1, i);

					if(it->sd.ft + 1 == n)
						return true;
				}
			}
		}
	}
	mpp.clear();
	return false;
}

main() {
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
//	fi(task".inp"), fo(task".out");
	
	int L = 0, R = 1e5;
	n = 1;
	int id = 3;
	while(cin >> s[n]) {
		R = min(R, int(s[n].size()));
		s[n] = ' ' + s[n];
		n++;
		id--;
		if(id == 0) break;
	}

	hsh.resize(n + 1);
	rep(i, 1, n) {
		hsh[i].resize(int(s[i].size()));
		rep(j, 1, int(s[i].size()) - 1)
			hsh[i][j] = (hsh[i][j - 1] * 26 + int(s[i][j] - 'A' + 1)) % mod;
	}
	rep(i, 1, 100000)
		po[i] = (po[i - 1] * 26) % mod;

	n--;
	while(L < R) {
		int mid = (L + R) / 2;
		if(check(mid) == true)
			R = mid;
		else L = mid + 1;
	}

	cout << L << "\n";

	end_debug;
}
