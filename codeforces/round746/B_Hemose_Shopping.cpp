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

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(c) ((int)(c).size())
#define all(c) (c).begin(), (c).end()
#define forn(i, a, b) for (int i = a, end = (b); i < end; i++)		 //[a,b)
#define fornr(i, a, b) for (int i = b - 1, end = (a); i >= end; i--) //[a,b) reversed
#define rep(i, a, b) for (int i = a, end = (b); i <= end; i++)		 //[a,b]
#define repr(i, a, b) for (int i = b, end = (a); i >= end; i--)		 //[a,b] reversed
#define setmin(a, b) a = min(a, b)
#define setmax(a, b) a = max(a, b)
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

bool isSorted(vi &a)
{
	bool sorted = true;
	forn(i, 1, sz(a))
	{
		if (a[i] < a[i - 1])
		{
			sorted = false;
			break;
		}
	}
	return sorted;
}
void solve()
{
	int n, x;
	cin >> n >> x;
	vi a(n);
	forn(i, 0, n)
	{
		cin >> a[i];
	}
	if (isSorted(a))
	{
		cout << "YES\n";
	}
	else
	{
		if (n == x)
		{
			cout << "NO\n";
		}
		else
		{
			int gap = (x) - (n - x);
			if (gap <= 0)
			{
				cout << "YES\n";
			}
			else
			{
				vi f, m;
				int l = (n - gap) / 2;
				forn(i, 0, l)
				{
					f.pb(a[i]);
				}
				forn(i, 0, l)
				{
					f.pb(a[n - 1 - i]);
				}
				forn(i, l, l + gap)
				{
					m.pb(a[i]);
				}
				sort(all(f));
				vi s;
				forn(i, 0, l)
				{
					s.pb(f[i]);
				}
				forn(i, 0, sz(m))
				{
					s.pb(m[i]);
				}
				forn(i, l, 2 * l)
				{
					s.pb(f[i]);
				}
				if (isSorted(s))
				{
					cout << "YES\n";
				}
				else
				{
					cout << "NO\n";
				}
			}
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
	while (t--)
	{
		solve();
	}
	return 0;
}