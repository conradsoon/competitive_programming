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

ll leq_count(ll n)
{
	//check 0
	if (n < 0)
	{
		return 0;
	}
	if (n == 0)
	{
		return 1;
	}
	string s = to_string(n);
	bool flag = false;
	vl pow(19, 1);
	forn(i, 1, sz(pow))
	{
		pow[i] = pow[i - 1] * 10;
	}
	while (!flag)
	{
		s = to_string(n);
		forn(i, 1, sz(s))
		{
			if (s[i] == s[i - 1])
			{
				n -= pow[sz(s) - i - 1];
				break;
			}
			if (i == sz(s) - 1)
			{
				flag = true;
			}
		}
	}
	reverse(all(s));
	vvl dp(2, vl(21, 0));
	dp[0][0] = 1;
	dp[1][0] = 1;
	ll ans = 1;
	rep(i, 1, sz(s))
	{
		dp[0][i] = dp[0][i - 1] * 9;
		dp[1][i] += dp[1][i - 1];
		dp[1][i] += (s[i - 1] - '0') * dp[0][i - 1];
		if (i < sz(s) && s[i - 1] > s[i])
		{
			dp[1][i] -= dp[0][i - 1];
		}
		ans += dp[1][i];
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a, b;
	cin >> a >> b;
	cout << leq_count(b) - leq_count(a - 1);
	return 0;
}