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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
int MAXN = 1e3 + 50;
void solve(int tc)
{
	int n, k;
	cin >> n >> k;
	vi b(n);
	vi c(n);
	vi kms(MAXN, INF);
	kms[1] = 0;
	forn(i, 1, MAXN)
	{
		repn(j, 1, i)
		{
			if (i + (i / j) < MAXN)
			{
				kms[i + (i / j)] = min(kms[i + (i / j)], kms[i] + 1);
			}
		}
	}
	forn(i, 0, n)
	{
		cin >> b[i];
	}
	forn(i, 0, n)
	{
		cin >> c[i];
	}
	vi knap(n);
	forn(i, 0, n)
	{
		/**
		int msb = 1;
		int d = 0;
		while (msb <= b[i])
		{
			msb <<= 1;
			d++;
		}
		msb >>= 1;
		d--;
		knap[i] = d + __builtin_popcount(b[i]) - 1;
		**/
		knap[i] = kms[b[i]];
	}
	int _k = 0;
	for (auto plo : knap)
	{
		_k += plo;
	}
	k = min(k, _k);
	vvl dp(n + 1, vl(k + 1, 0));
	repn(i, 1, n)
	{
		repn(j, 0, k)
		{
			dp[i][j] = dp[i - 1][j];
			if (j + knap[i - 1] <= k)
			{
				dp[i][j] = max(dp[i][j], dp[i - 1][j + knap[i - 1]] + c[i - 1]);
			}
		}
	}
	ll ans = 0;
	for (ll w : dp[n])
	{
		ans = max(ans, w);
	}
	cout << ans << "\n";
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