
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
	vi v_s(n);
	set<int> set_v_s;
	for (int i = 0; i < n; i++)
	{
		cin >> v_s[i];
		set_v_s.insert(v_s[i]);
	}
	map<int, ll> v;
	vi h_s(m);
	set<int> set_h_s;
	for (int i = 0; i < m; i++)
	{
		cin >> h_s[i];
		set_h_s.insert(h_s[i]);
	}
	map<int, ll> h;
	for (int i = 0; i < k; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		bool onVert = set_v_s.find(temp1) != set_v_s.end();
		bool onHori = set_h_s.find(temp2) != set_h_s.end();
		if (!(onVert & onHori))
		{
			if (onVert)
			{
				v[temp1]++;
			}
			if (onHori)
			{
				h[temp2]++;
			}
		}
	}
	ll ans = 0;
	for (auto kv : v)
	{
		ans += (kv.second) * (kv.second - 1);
	}
	for (auto kv : h)
	{
		ans += (kv.second) * (kv.second - 1);
	}
	cout << ans << "\n";
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