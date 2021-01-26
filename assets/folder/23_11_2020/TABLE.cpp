/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: TABLE **/

#include <bits/stdc++.h>

#define task				"TABLE"
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
const int maxn = 5e3 + 5;
const long long mod = 1e9 + 7;
const int base = 26;
const double pi = 3.14159265359;


/** End of template **/
/** Nếu bạn mất niềm tin vào cuộc sống, hãy đọc code này **/

ll s[maxn][maxn], a[maxn][maxn];
int n, m;
ll k;

bool check(int sz) {
	rep(i, 1, n - sz + 1) {
		int u = i + sz - 1;
		rep(j, 1, m - sz + 1) {
			int v = j + sz - 1;
			if(s[u][v] - s[i - 1][v] - s[u][j - 1] + s[i - 1][j - 1] <= k)
				return true;
		}
	}
	return false;
}

int in() {
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int ans = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) ans = ans * 10 + c - '0';
    return ans;
}

main()
{

//	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
//	fi(task".inp"), fo(task".out");
	
	n = in(), m = in(), k = in();
	bool ok = true;
	rep(i, 1, n)
		rep(j, 1, m) {
			a[i][j] = in();
			if(a[i][j] <= k)
				ok = false;
		}

	if(ok == true) {
		cout << 0 << "\n";
		return 0;
	}

	rep(i, 1, n)
		rep(j, 1, m)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];

	int L = 0, R = min(n, m);
	while(L <= R) {
		int mid = (L + R) / 2;
		if(check(mid) == true)
			L = mid + 1;
		else R = mid - 1;
	}

	cout << L - 1 << "\n";
}