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

struct seg
{
	ll l;
	ll r;
	ll c;
};
struct cost
{
	ll l;
	ll c;
};
cost findCost(vector<seg> &segs, int i, int j)
{
	ll l = max(segs[i].r, segs[j].r) - min(segs[i].l, segs[j].l) + 1;
	ll c = segs[i].c + segs[j].c;
	if (i == j)
	{
		c /= 2;
	}
	return {l, c};
}
bool operator<(const cost &lhs, const cost &rhs)
{
	if (lhs.l == rhs.l)
	{
		return lhs.c > rhs.c;
	}
	return lhs.l < rhs.l;
}
void solve(int tc)
{
	ll n;
	cin >> n;
	vector<seg> segs(n);
	forn(i, 0, n)
	{
		cin >> segs[i].l >> segs[i].r >> segs[i].c;
	}
	ll lb = 0, rb = 0;
	cost ccost = findCost(segs, lb, rb);
	cout << ccost.c << "\n";
	forn(i, 1, n)
	{
		vector<cost> r;
		r.pb(findCost(segs, lb, rb));
		r.pb(findCost(segs, i, rb));
		r.pb(findCost(segs, lb, i));
		r.pb(findCost(segs, i, i));
		sort(all(r));
		if (ccost < r.back())
		{
			ccost = r.back();
		}
		if (segs[i].l < segs[lb].l || segs[i].l == segs[lb].l && segs[i].c < segs[lb].c)
		{
			lb = i;
		}
		if (segs[i].r > segs[rb].r || segs[i].r == segs[rb].r && segs[i].c < segs[rb].c)
		{
			rb = i;
		}
		cout << ccost.c << "\n";
	}
	/**
	ll lb = INF, rb = -INF, lbc = INF, rbc = INF;
	ll lbidx = 0, rbidx = 0;
	cout << segs[lbidx].c << "\n";
	forn(i, 1, n)
	{
		int curr_cost = segs[lbidx].c + segs[rbidx].c;
		if (lbidx == rbidx)
		{
			curr_cost /= 2;
		}
		if (segs[i].l < segs[lbidx].l || segs[i].l == segs[lbidx].l && segs[i].c < segs[lbidx].c)
		{
			lbidx = i;
		}
		if (segs[i].r > segs[rbidx].r || segs[i].r == segs[rbidx].r && segs[i].c < segs[rbidx].c)
		{
			rbidx = i;
		}
		cout << curr_cost << "\n";
	}
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