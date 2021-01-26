/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: erase **/

#include <bits/stdc++.h>

#define task				"erase"
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

int Count(int X) {
	if(X == 0) return 1;
	int cnt = 0;
	while(X > 0) {
		X /= 10;
		cnt++;
	}
	return cnt;
}

int Off(int X, int id) {
    int _X = 0, cnt = 0, T = 1;
    while(X > 0) {
		cnt++;
        if(cnt != id) {
            _X = _X + (X % 10) * T;
            T *= 10;
        }
        X /= 10;
	}
	return _X;
}

ll S, _S, dig[maxn];
ll sig[maxn];
string s;

main()
{
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> s;
	int n = s.size(), cnt = 1;
	s = ' ' + s;
	sig[1] = true;
	rep(i, 1, n) {
		if('0' <= s[i] && s[i] <= '9')
			dig[cnt] = dig[cnt] * 10 + int(s[i] - '0');
		else {
			cnt++;
			sig[cnt] = (s[i] == '+') ? 1 : -1;
		}
	}

	rep(i, 1, cnt)
		S = S + dig[i] * sig[i];

    _S = LLONG_MIN;
	rep(i, 2, cnt) {
	    ll __S = S - dig[i - 1] * sig[i - 1] - dig[i] * sig[i];

	    ll T = 1;
	    rep(j, 1, Count(dig[i])) T *= 10;

	    __S = __S + (dig[i - 1] * T + dig[i]) * sig[i - 1];
		_S = max(_S, __S);
	}

    rep(i, 1, cnt) {
        rep(j, 1, Count(dig[i])) {
            ll __S = S - dig[i] * sig[i] + Off(dig[i], j) * sig[i];
            _S = max(_S, __S);
        }
    }

	cout << _S << "\n";

	end_debug;
}
