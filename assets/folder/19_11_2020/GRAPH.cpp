/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: GRAPH **/

#include <bits/stdc++.h>

#define task				"GRAPH"
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

#define int 				long long
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

int n, d[maxn], cnt[maxn], a[maxn], s[maxn];

void testcase() {
    cin >> n;
    rep(i, 1, n)
    	cnt[i] = 0;

    rep(i, 1, n) {
    	cin >> d[i];
    	if(d[i] >= n) {
    		cout << "NO\n";
            return ;
        }
    	cnt[d[i]]++;
    }

    int id = 0;
    repd(i, n, 1) {
    	while(cnt[i] > 0)
    		a[++id] = i, cnt[i]--;
    }

    rep(i, 1, n)
    	s[i] = s[i - 1] + a[i];

    if(s[n] % 2 == 1) {
        cout << "NO\n";
        return ;
    }

    id = n;
	rep(i, 1, n - 1) {
    	while(id > 1 && a[id] <= i)
    		id--;
    	int Right = s[n] - s[max(id, i)];
    	if(id > i)
    		Right += (id - i) * i;

    	if(s[i] > i * (i - 1) + Right) {
	    	cout << "NO\n";
    		return ;
    	}
    }

    cout << "YES\n";
    return ;
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

/*
7
4 3 3 3 3
6 2 4 5 5 2 1
5 3 2 3 2 1
6 2 4 5 5 2 2
6 2 4 2 2 2 2
10 9 9 9 9 9 9 9 9 9 9
6 6 5 4 3 2 1
*/
