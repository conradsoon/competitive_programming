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
using vvb = vector<vector<bool>>;

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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vvb v(n, vb(m, true));
	vector<vector<char>> p(n, vector<char>(m, 'X'));
	pii st, en;
	forn(i, 0, n)
	{
		string t;
		cin >> t;
		forn(j, 0, m)
		{
			if (t[j] != '#')
			{
				v[i][j] = false;
			}
			if (t[j] == 'A')
			{
				st = {i, j};
			}
			if (t[j] == 'B')
			{
				en = {i, j};
			}
		}
	}
	queue<pii> q;
	q.push(st);
	v[st.fi][st.se] = true;
	bool flag = false;
	while (!q.empty())
	{
		pii f = q.front();
		q.pop();
		if (f == en)
		{
			flag = true;
			break;
		}
		f.fi--;
		if (f.fi >= 0 && !v[f.fi][f.se])
		{
			v[f.fi][f.se] = true;
			p[f.fi][f.se] = 'D';
			q.push(f);
		}
		f.fi++;
		f.se--;
		if (f.se >= 0 && !v[f.fi][f.se])
		{
			v[f.fi][f.se] = true;
			p[f.fi][f.se] = 'R';
			q.push(f);
		}
		f.se++;
		f.fi++;
		if (f.fi < n && !v[f.fi][f.se])
		{
			v[f.fi][f.se] = true;
			p[f.fi][f.se] = 'U';
			q.push(f);
		}
		f.fi--;
		f.se++;
		if (f.se < m && !v[f.fi][f.se])
		{
			v[f.fi][f.se] = true;
			p[f.fi][f.se] = 'L';
			q.push(f);
		}
		f.se--;
	}
	string ans;
	pii pos = en;
	if (flag)
	{
		while (p[pos.fi][pos.se] != 'X')
		{
			if (p[pos.fi][pos.se] == 'R')
			{
				ans.pb('L');
				pos.se++;
			}
			else if (p[pos.fi][pos.se] == 'L')
			{
				ans.pb('R');
				pos.se--;
			}
			else if (p[pos.fi][pos.se] == 'U')
			{
				ans.pb('D');
				pos.fi--;
			}
			else if (p[pos.fi][pos.se] == 'D')
			{
				ans.pb('U');
				pos.fi++;
			}
		}
		reverse(all(ans));
		cout << "YES\n";
		cout << sz(ans) << "\n";
		cout << ans;
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}