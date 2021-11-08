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
bool bfs(vector<vector<char>> &map, vector<vector<char>> &v, pii ij)
{
	bool m_found = false;
	bool a_found = false;
	queue<pii> q1;
	q1.push(ij);
	while (!(m_found || a_found) && sz(q1) > 0)
	{
		queue<pii> q2;
		while (!q1.empty())
		{
			pii fr = q1.front();
			q1.pop();
			if (map[fr.fi][fr.se] == 'M')
			{
				m_found = true;
			}
			if (map[fr.fi][fr.se] == 'A')
			{
				a_found = true;
			}
			fr.fi--;
			if (fr.fi >= 0 && !v[fr.fi][fr.se] && map[fr.fi][fr.se] != '#')
			{
				q2.push(fr);
				v[fr.fi][fr.se] = 'D';
			}
			fr.fi++;
			fr.fi++;
			if (fr.fi < sz(map) && !v[fr.fi][fr.se] && map[fr.fi][fr.se] != '#')
			{
				q2.push(fr);
				v[fr.fi][fr.se] = 'U';
			}
			fr.fi--;
			fr.se--;
			if (fr.se >= 0 && !v[fr.fi][fr.se] && map[fr.fi][fr.se] != '#')
			{
				q2.push(fr);
				v[fr.fi][fr.se] = 'R';
			}
			fr.se++;
			fr.se++;
			if (fr.se < sz(map[0]) && !v[fr.fi][fr.se] && map[fr.fi][fr.se] != '#')
			{
				q2.push(fr);
				v[fr.fi][fr.se] = 'L';
			}
			fr.se--;
		}
		swap(q1, q2);
	}
	return !m_found;
}

string path(vector<vector<char>> &v, pii exit, pii a_loc)
{
	string s;
	pii curr_loc = a_loc;
	while (curr_loc != exit)
	{
		char d = v[curr_loc.fi][curr_loc.se];
		s.pb(d);
		if (d == 'D')
		{
			curr_loc.fi++;
		}
		else if (d == 'U')
		{
			curr_loc.fi--;
		}
		else if (d == 'R')
		{
			curr_loc.se++;
		}
		else if (d == 'L')
		{
			curr_loc.se--;
		}
	}
	return s;
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
	forn(i, 0, n)
	{
		forn(j, 0, m)
		{
			if (map[i][j] == 'A')
			{
				a_loc = {i, j};
			}
		}
	}
	queue<pii> e;
	forn(i, 0, n)
	{
		e.push({i, 0});
		e.push({i, m - 1});
	}
	forn(j, 0, m)
	{
		e.push({0, j});
		e.push({n - 1, j});
	}
	bool flag = false;
	while (!e.empty())
	{
		pii fr = e.front();
		e.pop();
		if (map[fr.fi][fr.se] != '#')
		{
			vector<vector<char>> v(n, vector<char>(m, false));
			flag = bfs(map, v, fr);
			if (flag)
			{
				string p = path(v, fr, a_loc);
				cout << "YES\n";
				cout << sz(p) << "\n";
				cout << p << "\n";
				return 0;
			}
		}
	}
	if (!flag)
	{
		cout << "NO\n";
	}
	return 0;
}