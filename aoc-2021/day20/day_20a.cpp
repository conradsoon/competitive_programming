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
	freopen("input.txt", "r", stdin);
	freopen("output_a.txt", "w", stdout);
	int ITRMAX = 50;
	int CONVSZN = 3;
	int CONVSZM = 3;
	int BUFFSZ = 60;
	string as;
	cin >> as;
	vector<string> inp;
	string t;
	while (cin >> t)
	{
		inp.pb(t);
	}
	int ninp = sz(inp);
	int minp = sz(inp[0]);
	int nb = 2 * BUFFSZ + ninp;
	int mb = 2 * BUFFSZ + minp;
	vector<vb> brd(nb, vb(mb, '.'));
	vector<vb> brdn(nb, vb(mb, '.'));
	forn(i, 0, ninp)
	{
		forn(j, 0, minp)
		{
			brd[i + BUFFSZ][j + BUFFSZ] = inp[i][j];
		}
	}
	forn(i, 0, nb)
	{
		forn(j, 0, mb)
		{
			cout << brd[i][j];
		}
		cout << endl;
	}
	forn(itr, 0, ITRMAX)
	{
		forn(i, 1, nb - 1)
		{
			forn(j, 1, mb - 1)
			{
				int pos = 0;
				forn(ci, 0, CONVSZN)
				{
					forn(cj, 0, CONVSZM)
					{
						int bt = ci * 3 + cj;
						bt = 8 - bt;
						pos ^= ((brd[i + ci - 1][j + cj - 1] == '#') << bt);
					}
				}
				brdn[i][j] = as[pos];
			}
		}
		// accounts for infinite size
		char c;
		if (itr % 2)
		{
			c = '.';
		}
		else
		{
			c = '#';
		}
		forn(j, 0, mb)
		{
			brdn[0][j] = c;
			brdn[nb - 1][j] = c;
		}
		forn(i, 0, mb)
		{
			brdn[i][0] = c;
			brdn[i][mb - 1] = c;
		}
		swap(brd, brdn);
		forn(i, 0, nb)
		{
			forn(j, 0, mb)
			{
				cout << brd[i][j];
			}
			cout << endl;
		}
	}
	ll c = 0;
	forn(i, 0, nb)
	{
		forn(j, 0, mb)
		{
			c += brd[i][j] == '#';
		}
	}
	cout << c;
	return 1;
}
