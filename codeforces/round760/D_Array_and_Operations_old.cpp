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
using vb = vector<char>; // char faster
using vvb = vector<vector<char>>;

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
	int n, k;
	cin >> n >> k;
	vi a(n);
	forn(i, 0, n)
	{
		cin >> a[i];
	}
	map<int, int> f;
	for (auto x : a)
	{
		f[x]++;
	}
	priority_queue<pii> pq;
	for (auto kv : f)
	{
		pq.push({kv.se, kv.fi});
	}
	int c = 0;
	ll ans = 0;
	while (!pq.empty() && c != k)
	{
		pii t1 = pq.top();
		pq.pop();
		if (pq.empty())
		{
			t1.fi -= (k - c) * 2;
			ans += (k - c);
			pq.push(t1);
			break;
		}
		pii t2 = pq.top();
		pq.pop();
		if (t1.fi >= 2 && t1.se * 2 + 1 > t1.se + t2.se)
		{
			t1.fi -= 2;
			ans += 1;
		}
		else
		{
			t1.fi--;
			t2.fi--;
		}
		c++;
		if (t1.fi)
		{
			pq.push(t1);
		}
		if (t2.fi)
		{
			pq.push(t2);
		}
	}
	while (!pq.empty())
	{
		pii t = pq.top();
		pq.pop();
		ans += t.fi * t.se;
	}
	cout << ans << "\n";

	/**
	sort(all(a));
	vb v(n, false);
	int c = 0;
	ll ans = 0;
	fornr(i, 0, n)
	{
		if (c == k)
		{
			break;
		}
		if (!v[i])
		{
			fornr(j, 0, i)
			{
				if (!v[j] && a[j] != a[i])
				{
					v[j] = true;
					v[i] = true;
					c++;
					break;
				}
			}
		}
	}
	if (k != c)
	{
		fornr(i, 0, n)
		{
			if (c == k)
			{
				break;
			}
			if (!v[i])
			{
				fornr(j, 0, i)
				{
					if (!v[j])
					{
						ans++;
						v[j] = true;
						v[i] = true;
						c++;
						break;
					}
				}
			}
		}
	}
	forn(i, 0, n)
	{
		if (!v[i])
		{
			ans += a[i];
		}
	}
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