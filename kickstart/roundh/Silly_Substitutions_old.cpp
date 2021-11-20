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
	list<char> l(all(s));
	vb nx(100, 0);
	vb pv(100, 0);
	forn(i, 0, 10)
	{
		nx['0' + i] = '0' + i + 1;
		pv['0' + i] = '0' + i - 1;
	}
	nx['9'] = '0';
	pv['0'] = '9';
	forn(k, 0, n + 5)
	{
		for (int i = 0; i < 10; i++)
		{
			char cr = '0' + i;
			bool flag = false;
			for (auto itr = ++l.begin(); itr != l.end(); itr++)
			{
				if (flag)
				{
					auto itrp1 = itr;
					--itrp1;
					--itrp1;
					l.erase(itrp1, itr);
					l.insert(itr, nx[nx[cr]]);
					flag = false;
				}
				if (*itr == nx[cr])
				{
					auto itrp = itr;
					--itrp;
					if (*itrp == cr)
					{
						flag = true;
					}
				}
			}
			if (flag)
			{
				auto itrp1 = l.end();
				--itrp1;
				--itrp1;
				l.erase(itrp1, l.end());
				l.insert(l.end(), nx[nx[cr]]);
				flag = false;
			}
		}
	}
	cout << "Case #" << tc << ": ";
	for (auto c : l)
	{
		cout << c;
	}
	cout << "\n";
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