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

void ppath(vvb &av, int i, int j)
{
	string s;
	while (av[i][j] != 'X')
	{
		char d = av[i][j];
		s.pb(d);
		if (d == 'U')
		{
			i++;
		}
		else if (d == 'D')
		{
			i--;
		}
		else if (d == 'R')
		{
			j--;
		}
		else if (d == 'L')
		{
			j++;
		}
	}
	reverse(all(s));
	cout << "YES\n";
	cout << sz(s) << "\n";
	cout << s << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<char>> map(n, vector<char>(m, '.'));
	forn(i, 0, n)
	{
		string s;
		cin >> s;
		map[i] = vector<char>(s.begin(), s.end());
	}
	pii a_loc;
	vvb av(n, vb(m, false));
	vvb mv(n, vb(m, false));
	queue<pii> qa1;
	queue<pii> qm1;
	forn(i, 0, n)
	{
		forn(j, 0, m)
		{
			if (map[i][j] == 'A')
			{
				av[i][j] = 'X';
				qa1.push({i, j});
				a_loc = {i, j};
			}
			else if (map[i][j] == 'M')
			{
				mv[i][j] = true;
				qm1.push({i, j});
			}
		}
	}
	while (!qa1.empty())
	{
		queue<pii> qa2;
		queue<pii> qm2;
		while (!qm1.empty())
		{
			int i = qm1.front().fi;
			int j = qm1.front().se;
			qm1.pop();
			i--;
			if (i >= 0 && map[i][j] != '#' && !mv[i][j])
			{
				mv[i][j] = true;
				qm2.push({i, j});
			}
			i++;
			j--;
			if (j >= 0 && map[i][j] != '#' && !mv[i][j])
			{
				mv[i][j] = true;
				qm2.push({i, j});
			}
			j++;
			i++;
			if (i < n && map[i][j] != '#' && !mv[i][j])
			{
				mv[i][j] = true;
				qm2.push({i, j});
			}
			i--;
			j++;
			if (j < m && map[i][j] != '#' && !mv[i][j])
			{
				mv[i][j] = true;
				qm2.push({i, j});
			}
			j--;
		}
		swap(qm1, qm2);
		while (!qa1.empty())
		{
			int i = qa1.front().fi;
			int j = qa1.front().se;
			qa1.pop();
			i--;
			if (i >= 0 && map[i][j] != '#' && !av[i][j] && !mv[i][j])
			{
				av[i][j] = 'U';
				qa2.push({i, j});
			}
			i++;
			j--;
			if (j >= 0 && map[i][j] != '#' && !av[i][j] && !mv[i][j])
			{
				av[i][j] = 'L';
				qa2.push({i, j});
			}
			j++;
			i++;
			if (i < n && map[i][j] != '#' && !av[i][j] && !mv[i][j])
			{
				av[i][j] = 'D';
				qa2.push({i, j});
			}
			i--;
			j++;
			if (j < m && map[i][j] != '#' && !av[i][j] && !mv[i][j])
			{
				av[i][j] = 'R';
				qa2.push({i, j});
			}
			j--;
		}
		swap(qa1, qa2);
	}
	forn(i, 0, n)
	{
		if (av[i][0])
		{
			ppath(av, i, 0);
			return 0;
		}
		if (av[i][m - 1])
		{
			ppath(av, i, m - 1);
			return 0;
		}
	}
	forn(j, 0, m)
	{
		if (av[0][j])
		{
			ppath(av, 0, j);
			return 0;
		}
		if (av[n - 1][j])
		{
			ppath(av, n - 1, j);
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}