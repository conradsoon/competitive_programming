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

int main()
{
	int b_idx;
	//vvi r(6);
	vi r;
	vi ord(5);
	cout << "Order for indices:"
		 << "0 1 2 3 4"
		 << "?\n";
	forn(i, 0, 5)
	{
		cin >> ord[i];
	}
	b_idx = ord[0];
	r.pb(b_idx);
	//r[0].pb(b_idx);
	repn(k, 1, 5)
	{
		int st = 5 + 4 * (k - 1);
		cout << "Order for indices: ";
		cout << b_idx << " ";
		forn(j, 0, 4)
		{
			cout << st + j << " ";
		}
		cout << "?\n";
		forn(i, 0, 5)
		{
			cin >> ord[i];
		}
		b_idx = ord[0];
		forn(i, 0, 5)
		{
			r.pb(ord[i]);
			if (ord[i] == b_idx)
			{
				break;
			}
		}
	}
	ll c = 0;
	bool flag = false;
	reverse(all(r));
	//gets rids of duplicates basically
	auto it = unique(all(r));
	r.resize(distance(r.begin(), it));
	forn(i, 0, 3)
	{
		cout << r[i] << " ";
	}
	return 0;
}