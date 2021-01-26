/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: ASTR **/

#include <bits/stdc++.h>

#define task				"ASTR"
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
const long long mod = 111539786;
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

string t, p, s;
int f[maxn], n, m;

void sufpre() {
	rep(i, 1, m)
		f[i] = 0;

	rep(i, 1, m) {
		t[i] = (p[i] == '0') ? '1' : '0';
		repd(ft, i, 1) {
			rep(j, ft, i + 1) {
				if(j == i + 1)
					f[i] = max(f[i], i - ft + 1);
				if(t[j] != p[j - ft + 1])
					break;
			}
		}
		t[i] = p[i];
	}
}

int dp[maxn][12], ans;

struct Matrix {
	int r = 0, c = 0;
	int val[12][12] = {{0}};

	Matrix operator * (const Matrix &P) {
		Matrix ans;
		ans.r = r, ans.c = P.c;
		rep(i, 1, r)
			rep(j, 1, P.c) {
				ans.val[i][j] = 0;
				rep(k, 1, c)
					ans.val[i][j] = (ans.val[i][j] + val[i][k] * P.val[k][j]) % mod;
			}
		return ans;
	}

	Matrix operator ^ (const int &P) {
		if(P == 1) return (*this);
		Matrix ans = (*this) ^ (P / 2);
		if(P % 2 == 0) return ans * ans;
		else return ans * ans * (*this);
	}
};

void solve() {
	Matrix X, Y;

	X.r = X.c = m + 1;
	rep(j, 1, m) {
		X.val[j + 1][j] = 1;
		X.val[f[j] + 1][j] = 1;
	}

	Y.r = m + 1, Y.c = 1;
	Y.val[1][1] = 1;
	rep(i, 2, m + 1)
		Y.val[i][1] = 0;

    X = X ^ n;

    rep(i, 1, m + 1) {
		rep(j, 1, m + 1)
			cerr << X.val[i][j] << " ";
		cerr << "\n";
	}

	Y = X * Y;

	rep(i, 1, m)
		ans = (ans + Y.val[i][1]) % mod;
}

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	while(cin >> n >> p)
	 {
		m = p.size();
		p = ' ' + p;
		sufpre();
		ans = 0;
		solve();
		cout << ans << "\n";
	}

	end_debug;
}
