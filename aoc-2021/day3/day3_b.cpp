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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output_b.txt", "w", stdout);
	vector<string> inp;
	string test;
	while (cin >> test)
	{
		inp.pb(test);
	}
	sort(all(inp));
	int k = sz(inp[0]);
	string s(k, '0');
	string b(k, '1');
	int o2;
	int co2;
	auto l = inp.begin();
	auto r = inp.end();
	forn(i, 0, k)
	{
		int n = r - l;
		if (n == 1)
		{
			break;
		}
		int c = 0;
		for (auto itr = l; itr != r; itr++)
		{
			if ((*itr)[i] == '1')
			{
				c++;
			}
		}
		if (c >= (n + 1) / 2)
		{
			s[i] = '1';
			b[i] = '1';
		}
		else
		{
			s[i] = '0';
			b[i] = '0';
		}
		l = lower_bound(l, r, s);
		r = upper_bound(l, r, b);
	}
	s = string(k, '0');
	b = string(k, '1');
	co2 = stoi(*l, nullptr, 2);
	l = inp.begin();
	r = inp.end();
	forn(i, 0, k)
	{
		int n = r - l;
		if (n == 1)
		{
			break;
		}
		int c = 0;
		for (auto itr = l; itr != r; itr++)
		{
			if ((*itr)[i] == '1')
			{
				c++;
			}
		}
		if (c >= (n + 1) / 2)
		{
			s[i] = '0';
			b[i] = '0';
		}
		else
		{
			s[i] = '1';
			b[i] = '1';
		}
		l = lower_bound(l, r, s);
		r = upper_bound(l, r, b);
	}
	o2 = stoi(*l, nullptr, 2);
	cout << co2 * o2;
	return 0;
}
