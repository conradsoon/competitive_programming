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
const int MAXN = 500100;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

char nxc[100];
char pvc[100];

void solve(int tc)
{
	int n;
	cin >> n;
	int nx[n];
	int pv[n];
	char c[n];
	string s;
	cin >> s;
	forn(i, 0, n)
	{
		c[i] = s[i];
	}
	forn(i, 1, n)
	{
		pv[i] = i - 1;
	}
	pv[0] = -1;
	forn(i, 0, n - 1)
	{
		nx[i] = i + 1;
	}
	nx[n - 1] = -1;
	map<char, set<int>> sm;
	forn(i, 1, n)
	{
		if (pvc[c[i]] == c[pv[i]])
		{
			sm[c[i]].insert(i);
		}
	}
	while (true)
	{
		bool flag = false;
		for (auto kv : sm)
		{
			if (sz(kv.se))
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			break;
		}
		forn(i, 0, 10)
		{
			for (auto p : sm[nxc['0' + i]])
			{
				char currc = c[p];
				int prevp = pv[p];
				int nextp = nx[p];
				if (c[prevp] == pvc[currc])
				{
					c[prevp] = nxc[currc];
					if (pv[prevp] != -1)
					{
						if (pvc[c[prevp]] == c[pv[prevp]])
						{
							sm[c[prevp]].insert(prevp);
						}
					}
					nx[prevp] = nextp;
					if (nextp != -1)
					{
						pv[nextp] = prevp;
						if (nxc[c[prevp]] == c[nextp])
						{
							sm[c[nextp]].insert(nextp);
						}
					}
					pv[p] = -1;
					nx[p] = -1;
				}
			}
			sm[nxc['0' + i]] = set<int>();
		}
	}
	cout << "Case #" << tc << ": ";
	int idx = 0;
	while (idx != -1)
	{
		cout << c[idx];
		idx = nx[idx];
	}
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("ts2_input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	forn(i, 0, 10)
	{
		nxc['0' + i] = '0' + i + 1;
		pvc['0' + i] = '0' + i - 1;
	}
	nxc['9'] = '0';
	pvc['0'] = '9';
	repn(i, 1, t)
	{
		solve(i);
	}
	return 0;
}