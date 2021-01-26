/** Begin template. Do not change this part **/
/** Author: GrintonDH **/
/** Problem: SDINO **/

#include <bits/stdc++.h>

#define task				"SDINO"
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

/** Sử dụng sắp xếp trộn: Sắp xếp k phần tử trên cùng của stack **/
/** Đặt a = k / 2, b = k - a **/
/** Viết hàm: Sắp xếp a, ấn aS, aQ, ấn kS, kQ, sắp xếp b, merge(a, b)**/

stack<int> S;
queue<int> Q;
vector<char> ans;
#define pushQ		ans.pb('H'),S.push(Q.front()),Q.pop()
#define pushS		ans.pb('C'),Q.push(S.top()),S.pop()
int n;
void merge(int a, int b, bool ev) {
	int j = 1;
	rep(i, 1, b)
        pushS;

	rep(i, 1, b) {
		while(j <= a) {
			if(ev == true && S.top() > Q.front())
				j++, pushS;
			else if(ev == false && S.top() < Q.front())
				j++, pushS;
		} 
		pushQ, pushS;
	}

	while(j <= a)
        j++, pushS;

    rep(i, 1, a + b)
        pushQ;
}

void sorting(int k, bool ev) {
	if(k == 1) return ;

	int mid = k / 2;
	sorting(k / 2, 1 - ev);
	rep(i, 1, k)
		pushS;
	rep(i, 1, k)
		pushQ;
	sorting(k - k / 2, 1 - ev);
	merge(k / 2, k - k / 2, ev);
}

int a[maxn];
main() {
	start_debug;

	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

//	fi(task".inp"), fo(task".out");

	cin >> n;
	rep(i, 1, n)
		cin >> a[i];

	repd(i, n, 1)
		S.push(a[i]);

	sorting(n, true);

	repa(u, ans)
		cout << u;

	end_debug;
}
