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
using vb = vector<char>; //char faster
using vvb = vector<vector<char>>;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, a, b) for (int i = a, end = (b); i < end; i++)		 //[a,b)
#define fornr(i, a, b) for (int i = b - 1, end = (a); i >= end; i--) //[a,b) reversed
#define repn(i, a, b) for (int i = a, end = (b); i <= end; i++)		 //[a,b]
#define repnr(i, a, b) for (int i = b, end = (a); i >= end; i--)	 //[a,b] reversed
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

const int N = 200 * 100 + 50;
int lp[N + 1];
vector<int> pr;
set<int> prs;
void printu(vector<bool> &u)
{
	ll c = 0;
	forn(i, 0, sz(u))
	{
		if (u[i])
		{
			c++;
		}
	}
	cout << c << "\n";
	forn(i, 0, sz(u))
	{
		if (u[i])
		{
			cout << i + 1 << " ";
		}
	}
	cout << "\n";
}
void solve(int tc)
{
	int n;
	cin >> n;
	vi a(n);
	vector<bool> u(n, true);
	ll sum = 0;
	forn(i, 0, n)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (prs.find(sum) == prs.end())
	{
		printu(u);
		return;
	}
	forn(i, 0, n)
	{
		sum -= a[i];
		u[i] = false;
		if (prs.find(sum) == prs.end())
		{
			printu(u);
			return;
		}
		sum += a[i];
		u[i] = true;
	}
	forn(i, 0, n)
	{
		forn(j, i + 1, n)
		{
			sum -= a[i];
			u[i] = false;
			sum -= a[j];
			u[j] = false;
			if (prs.find(sum) == prs.end())
			{
				printu(u);
				return;
			}
			sum += a[i];
			u[i] = true;
			sum += a[j];
			u[j] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 2; i <= N; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			pr.pb(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
			lp[i * pr[j]] = pr[j];
	}
	for (auto x : pr)
	{
		prs.insert(x);
	}
	repn(i, 1, t)
	{
		solve(i);
	}
	return 0;
}