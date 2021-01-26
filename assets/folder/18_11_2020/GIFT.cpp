/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: GIFT **/

#include <bits/stdc++.h>

#define int long long

#define task				"GIFT"
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

struct Val {
	int sum;
	ll a, b, c;

	Val() {
		sum = -1;
		a = b = c = 0;
	}

	bool operator < (const Val &P) const {
		return sum < P.sum;
	}
};

Val dp[18][3][2][2][2];
int n[18];
ll a, b, c;

Val calc(int pos, int re, bool tA, bool tB, bool tC) {
	if(pos == 0) {
		if(tA == false && tB == false && tC == false && re == 0) {
			Val ret = Val();    
 			ret.sum = 0, ret.a = a, ret.b = b, ret.c = c;
			return ret;
		}
		else {
			Val ret = Val();
			ret.sum = -mod, ret.a = 0, ret.b = 0, ret.c = 0;
			return ret;
		}
	}

	if(dp[pos][re][tA][tB][tC].sum != -1) {
		Val rem = dp[pos][re][tA][tB][tC];
		long long d = 1;
		rep(i, 1, pos) d *= 10;
		rem.a = a * d + rem.a % d;
		rem.b = b * d + rem.b % d;
		rem.c = c * d + rem.c % d;
		return rem;
	}

	Val best = Val();
	best.sum = -mod, best.a = 0, best.b = 0, best.c = 0;

	int min2, min3;

	rep(ai, 0, 9) {
		a = a * 10 + ai;
		if(tB == false) min2 = 0;
		else min2 = ai;
		rep(bi, min2, 9) {
			b = b * 10 + bi;
			if(tC == false) min3 = 0;
			else min3 = bi;
			rep(ci, min3, 9) {
				c = c * 10 + ci;
				rep(nho2, 0, 2) {
					if((ai + bi + ci + nho2) / 10 != re)
						continue;
					if((ai + bi + ci + nho2) % 10 != n[pos])
						continue;
					bool nA = (ai > 0) ? 0 : tA;
					bool nB = (bi > ai) ? 0 : tB;
					bool nC = (ci > bi) ? 0 : tC;

					Val tmp = calc(pos - 1, nho2, nA, nB, nC);
					tmp.sum = ai + bi + ci + tmp.sum;
					if(tmp.sum < -1) tmp.sum = -mod;
					
					if(best.sum < tmp.sum)
						best = tmp;
				}
				c /= 10;
			}
			b /= 10;
		}
		a /= 10;
	}

	dp[pos][re][tA][tB][tC] = best;
	return best;
}

vector<ll> cs[4];
void tack(ll x, vector<ll> &P) {
    if(x == 0) return ;
	if(x <= 1) {
		P.pb(1);
		return ;
	}
	if(x % 2 == 0) {
		tack(x / 2, P);
		for(ll &v: P)
			v *= 2;
	}
	else {
		ll q = 1;
		while(q <= x)
			q *= 3;
		q /= 3;
		tack(x - q, P);
		P.pb(q);
	}
	return ;
}

void testcase() {
	ll nn;
	cin >> nn;

	rep(i, 0, 17)
		n[i] = 0;
	int cnt = 0;
	while(nn > 0) {
		n[++cnt] = nn % 10;
		nn /= 10;
	}

	a = 0, b = 0, c = 0;
	Val ans = calc(cnt, 0, true, true, true);
	if(ans.sum == -mod)
		cout << "-1\n";
	else {
        a = ans.a, b = ans.b, c = ans.c;
		tack(a, cs[1]), tack(b, cs[2]), tack(c, cs[3]);
		cout << cs[1].size() << " " << cs[2].size() << " " << cs[3].size() << " ";
		repa(v, cs[1])
			cout << v << " ";
		repa(v, cs[2])
			cout << v << " ";
		repa(v, cs[3])
			cout << v << " ";
		cout << "\n";
        rep(i, 1, 3)
            cs[i].clear();
	}

	rep(i, 0, cnt + 1)
			rep(j, 0, 2)
				rep(k, 0, 1)
					rep(l, 0, 1)
					rep(m, 0, 1)
						dp[i][j][k][l][m] = Val();
}

main() {
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), 
//	fo(task".out");

	int t; cin >> t;
	while(t--) {
		testcase();
	}

	end_debug;
}
