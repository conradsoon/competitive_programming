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

struct b
{
	int op;
	int xb;
	int xe;
	int yb;
	int ye;
	int zb;
	int ze;
};
void print(__int64_t x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("ans_str.txt", "w", stdout);
	cout << endl;
	int n;
	cin >> n;
	vector<b> bxs(n);
	set<int> xc;
	set<int> yc;
	set<int> zc;
	forn(i, 0, n)
	{
		cin >> bxs[i].op >> bxs[i].xb >> bxs[i].xe >> bxs[i].yb >> bxs[i].ye >> bxs[i].zb >> bxs[i].ze;
		bxs[i].xe++;
		bxs[i].ye++;
		bxs[i].ze++;
		/**
		bxs[i].xb = max(bxs[i].xb, -50);
		bxs[i].yb = max(bxs[i].yb, -50);
		bxs[i].zb = max(bxs[i].zb, -50);
		bxs[i].xe = min(bxs[i].xe, 51);
		bxs[i].ye = min(bxs[i].ye, 51);
		bxs[i].ze = min(bxs[i].ze, 51);
		**/
		xc.insert(bxs[i].xb);
		xc.insert(bxs[i].xe);
		yc.insert(bxs[i].yb);
		yc.insert(bxs[i].ye);
		zc.insert(bxs[i].zb);
		zc.insert(bxs[i].ze);
	}
	/**
	xc.insert(-50);
	xc.insert(51);
	yc.insert(-50);
	yc.insert(51);
	zc.insert(-50);
	zc.insert(51);
	**/
	int idx = 0;
	map<int, int> xc2i;
	map<int, int> xi2c;
	for (auto c : xc)
	{
		xc2i[c] = idx;
		xi2c[idx] = c;
		idx++;
	}
	map<int, int> yc2i;
	map<int, int> yi2c;
	idx = 0;
	for (auto c : yc)
	{
		yc2i[c] = idx;
		yi2c[idx] = c;
		idx++;
	}
	idx = 0;
	map<int, int> zc2i;
	map<int, int> zi2c;
	for (auto c : zc)
	{
		zc2i[c] = idx;
		zi2c[idx] = c;
		idx++;
	}
	int nx = sz(xc);
	int ny = sz(yc);
	int nz = sz(zc);
	vector<vector<vector<char>>> s(nx, vector<vector<char>>(ny, vector<char>(nz, 0)));
	int cnt = 0;
	for (auto b : bxs)
	{
		// cout << cnt << endl;
		for (int i = xc2i[b.xb]; i < xc2i[b.xe]; i++)
		{
			for (int j = yc2i[b.yb]; j < yc2i[b.ye]; j++)
			{
				for (int k = zc2i[b.zb]; k < zc2i[b.ze]; k++)
				{
					s[i][j][k] = b.op;
				}
			}
		}
		cnt++;
	}
	int128 ans = 0;
	// string ans_str = "";
	forn(i, 0, nx)
	{
		forn(j, 0, ny)
		{
			forn(k, 0, nz)
			{
				if (s[i][j][k])
				{
					/**
					ans_str.pb('(');
					ans_str.pb('(');
					ans_str.append(to_string(xi2c[i + 1]));
					ans_str.pb('-');
					ans_str.append(to_string(xi2c[i]));
					ans_str.pb(')');
					ans_str.pb('*');
					ans_str.pb('(');
					ans_str.append(to_string(yi2c[i + 1]));
					ans_str.pb('-');
					ans_str.append(to_string(yi2c[i]));
					ans_str.pb(')');
					ans_str.pb('*');
					ans_str.pb('(');
					ans_str.append(to_string(zi2c[i + 1]));
					ans_str.pb('-');
					ans_str.append(to_string(zi2c[i]));
					ans_str.pb(')');
					ans_str.pb(')');
					ans_str.pb('+');
					**/
					int128 t = 1;
					t *= ((int128)xi2c[i + 1] - xi2c[i]);
					t *= ((int128)yi2c[j + 1] - yi2c[j]);
					t *= ((int128)zi2c[k + 1] - zi2c[k]);
					ans += t;
				}
			}
		}
	}
	print(ans);
	cout << endl;
	return 1;
}
