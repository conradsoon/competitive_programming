#include <bits/stdc++.h>

using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, a, b) for (int i = a, __end = (b); i < __end; i++)		 //[a,b)
#define fornr(i, a, b) for (int i = b - 1, __end = (a); i >= __end; i--) //[a,b) reversed
#define repn(i, a, b) for (int i = a, __end = (b); i <= __end; i++)		 //[a,b]
#define repnr(i, a, b) for (int i = b, __end = (a); i >= __end; i--)	 //[a,b] reversed
#define setmin(a, b) a = min(a, (b))
#define setmax(a, b) a = max(a, (b))
#define NIL 0
#define INF INT_MAX
#define INFLL LLONG_MAX
#define int128 __int128_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double eps = 1e-9;
const long long mod = 1000000007;
const int MAXN = 200005;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(int tc)
{
	int n;
	cin >> n;
	vl a(n);
	vl b(n);
	forn(i, 0, n)
	{
		cin >> a[i];
	}
	forn(i, 0, n)
	{
		cin >> b[i];
	}
	ll al, ar, bl, br;
	al = a[0];
	ar = a.back();
	bl = b[0];
	br = b.back();
	sort(all(a));
	sort(all(b));
	ll ans = INFLL;
	ll bal, bar, bbl, bbr;
	bal = INFLL;
	for (auto x : b)
	{
		setmin(bal, abs(al - x));
	}
	bar = INFLL;
	for (auto x : b)
	{
		setmin(bar, abs(ar - x));
	}
	bbl = INFLL;
	for (auto x : a)
	{
		setmin(bbl, abs(bl - x));
	}
	bbr = INFLL;
	for (auto x : a)
	{
		setmin(bbr, abs(br - x));
	}
	setmin(ans, abs(al - br) + abs(ar - bl));
	setmin(ans, abs(al - bl) + abs(ar - br));
	setmin(ans, abs(al - bl) + bar + bbr);
	setmin(ans, abs(ar - br) + bal + bbl);
	setmin(ans, abs(ar - bl) + bal + bbr);
	setmin(ans, abs(al - br) + bar + bbl);
	setmin(ans, bal + bar + bbl + bbr);
	cout << ans << "\n";
	/**
	// 1
	setmin(ans, abs(al - br) + abs(ar - bl));
	// 2
	setmin(ans, abs(al - bl) + abs(ar - br));
	// 3
	ll test = 0;
	test += abs(al - bl);
	auto lb1 = lower_bound(all(b), ar);
	auto lb2 = lower_bound(all(a), br);
	test += abs(ar - min(*lb1, *(--lb1)));
	test += abs(br - min(*lb2, *(--lb2)));
	setmin(ans, test);
	// 4
	test = 0;
	test += abs(ar - br);
	lb1 = lower_bound(all(b), al);
	lb2 = lower_bound(all(a), bl);
	test += abs(al - min(*lb1, *(--lb1)));
	test += abs(bl - min(*lb2, *(--lb2)));
	setmin(ans, test);
	// 5
	test = 0;
	test += abs(ar - bl);
	lb1 = lower_bound(all(b), al);
	lb2 = lower_bound(all(a), br);
	test += abs(al - min(*lb1, *(--lb1)));
	test += abs(br - min(*lb2, *(--lb2)));
	setmin(ans, test);
	// 6
	test = 0;
	test += abs(al - br);
	lb1 = lower_bound(all(b), ar);
	lb2 = lower_bound(all(a), bl);
	test += abs(ar - min(*lb1, *(--lb1)));
	test += abs(bl - min(*lb2, *(--lb2)));
	setmin(ans, test);
	// 7
	test = 0;
	test += abs(al - br);
	lb1 = lower_bound(all(b), al);
	lb2 = lower_bound(all(b), ar);
	auto lb3 = lower_bound(all(a), bl);
	auto lb4 = lower_bound(all(a), br);
	test += abs(al - min(*lb1, *(--lb1)));
	test += abs(ar - min(*lb2, *(--lb2)));
	test += abs(bl - min(*lb3, *(--lb3)));
	test += abs(br - min(*lb4, *(--lb4)));
	setmin(ans, test);
	cout << ans << "\n";
	**/
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	repn(i, 1, t)
	{
		solve(i);
	}
	return 0;
}