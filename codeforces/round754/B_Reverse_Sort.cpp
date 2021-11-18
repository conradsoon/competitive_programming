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
	string s;
	cin >> s;
	string srted = s;
	sort(all(srted));
	vvi ans;
	while (s != srted)
	{
		vi pfx1(n, 0);
		pfx1[0] = s[0] == '1';
		vi pfx0(n, 0);
		pfx0[0] = s[0] == '0';
		forn(i, 1, n)
		{
			pfx1[i] = pfx1[i - 1];
			pfx1[i] += s[i] == '1';
			pfx0[i] = pfx0[i - 1];
			pfx0[i] += s[i] == '0';
		}
		int idx = 0;
		while (pfx1[idx] <= pfx0[n - 1] - pfx0[idx])
		{
			idx++;
		}
		idx--;
		vi sidx;
		repn(i, 0, idx)
		{
			if (s[i] == '1')
			{
				sidx.pb(i);
			}
		}
		forn(i, idx, n)
		{
			if (s[i] == '0')
			{
				sidx.pb(i);
			}
		}
		forn(i, 0, sz(sidx) / 2)
		{
			swap(s[sidx[i]], s[sidx[sz(sidx) - 1 - i]]);
		}
		ans.pb(sidx);
		cout << "\n";
	}
	cout << sz(ans) << "\n";
	for (auto ve : ans)
	{
		cout << sz(ve) << " ";
		for (auto x : ve)
		{
			cout << x + 1 << " ";
		}
		cout << "\n";
	}
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