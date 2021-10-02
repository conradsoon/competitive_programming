
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
	ll n, m, k;
	cin >> n >> m >> k;
	if (m < n - 1)
	{
		//unconnected
		cout << "NO\n";
		return;
	}
	if (m > n * (n - 1) / 2)
	{
		//self-loop
		cout << "NO\n";
		return;
	}
	if (k <= 1)
	{
		//min distance is still 0;
		cout << "NO\n";
		return;
	}
	if (n == 1 && m == 0)
	{
		cout << "YES\n";
		return;
	}
	ll max_d = min(k - 2, n - 1);
	ll min_edges = 0;
	if (max_d == 0)
	{
		cout << "NO\n";
		return;
	}
	else if (max_d == 1)
	{
		min_edges = n * (n - 1) / 2;
	}
	else
	{
		min_edges += max_d;
		min_edges += (n - (max_d + 1));
	}
	if (m >= min_edges)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
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