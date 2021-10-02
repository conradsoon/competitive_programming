
#include <bits/stdc++.h>

using namespace std;

//TYPEDEFS
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

//MACROS
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define REPR(i, a, b) for (int i = b; i >= a; i--)
//template ends
void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	vi v(n);
	for (auto &x : v)
	{
		cin >> x;
	}
	vi h(m);
	for (auto &x : h)
	{
		cin >> x;
	}
	vll h_s(n);
	vll v_s(m);
	map<pii, ll> same_str_hori;
	map<pii, ll> same_str_vert;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		bool onHori = false;
		bool onVert = false;
		int hori;
		int vert;
		//find hori str
		auto lbv = lower_bound(v.begin(), v.end(), x);
		auto lbh = lower_bound(h.begin(), h.end(), y);
		if (x == *lbv)
		{
			onVert = true;
		}
		if (y == *lbh)
		{
			onHori = true;
		}
		if (!(onHori & onVert))
		{
			hori = lbv - v.begin();
			vert = lbh - h.begin();
			if (onHori)
			{
				same_str_hori[{hori, vert}]++;
				h_s[hori]++;
			}
			if (onVert)
			{
				same_str_vert[{hori, vert}]++;
				v_s[vert]++;
			}
		}
	}
	ll count = 0;
	for (auto x : h_s)
	{
		count += x * (x - 1) / 2;
	}
	for (auto x : v_s)
	{
		count += x * (x - 1) / 2;
	}
	for (auto kv : same_str_hori)
	{
		count -= kv.second * (kv.second - 1) / 2;
	}
	for (auto kv : same_str_vert)
	{
		count -= kv.second * (kv.second - 1) / 2;
	}
	cout << count << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}