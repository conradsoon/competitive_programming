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
	vi a_idx;
	vi pfxa(n + 1, 0);
	pfxa[1] = s[0] == 'a';
	vi pfxb(n + 1, 0);
	pfxb[1] = s[0] == 'b';
	vi pfxc(n + 1, 0);
	pfxc[1] = s[0] == 'c';
	forn(i, 1, n)
	{
		pfxa[i + 1] = pfxa[i];
		pfxa[i + 1] += s[i] == 'a';
		pfxb[i + 1] = pfxb[i];
		pfxb[i + 1] += s[i] == 'b';
		pfxc[i + 1] = pfxc[i];
		pfxc[i + 1] += s[i] == 'c';
	}
	forn(i, 0, n)
	{
		if (s[i] == 'a')
		{
			a_idx.pb(i);
		}
	}
	if (sz(a_idx) <= 1)
	{
		cout << -1 << "\n";
		return;
	}
	bool flag = false;
	int ans = INF;
	forn(i, 0, sz(a_idx))
	{
		if (i + 1 < sz(a_idx))
		{
			int strt = a_idx[i];
			int endi = a_idx[i + 1];
			endi++;
			int ac = pfxa[endi] - pfxa[strt];
			int bc = pfxb[endi] - pfxb[strt];
			int cc = pfxc[endi] - pfxc[strt];
			if (ac > bc && ac > cc)
			{
				setmin(ans, endi - strt);
				flag = true;
			}
		}
		if (i + 2 < sz(a_idx))
		{
			int strt = a_idx[i];
			int endi = a_idx[i + 2];
			endi++;
			int ac = pfxa[endi] - pfxa[strt];
			int bc = pfxb[endi] - pfxb[strt];
			int cc = pfxc[endi] - pfxc[strt];
			if (ac > bc && ac > cc)
			{
				setmin(ans, endi - strt);
				flag = true;
			}
		}
	}
	if (flag)
	{
		cout << ans << "\n";
	}
	else
	{
		cout << -1 << "\n";
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