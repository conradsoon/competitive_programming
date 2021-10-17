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

vector<int> parent(1e5, -1);
vector<int> sze(1e5, -1);
void make_set(int v)
{
	parent[v] = v;
	sze[v] = 1;
}
int find_set(int v)
{
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if (a != b)
	{
		if (sze[a] < sze[b])
			swap(a, b);
		parent[b] = a;
		sze[a] += sze[b];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	forn(i, 0, n)
	{
		make_set(i);
	}
	forn(i, 0, m)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		union_sets(a, b);
	}
	set<int> p;
	forn(i, 0, n)
	{
		p.insert(find_set(i));
	}
	cout << sz(p) - 1 << "\n";
	auto itr = p.begin();
	int prev = *itr;
	itr++;
	for (; itr != p.end(); itr++)
	{
		cout << (*itr) + 1 << " " << prev + 1 << "\n";
		prev = *itr;
	}
	return 0;
}