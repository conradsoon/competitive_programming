
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
	int n;
	cin >> n;
	vi a(n);
	vi b(n);
	vi b_max(n);
	REP(i, 0, n - 1)
	{
		cin >> a[i];
	}
	REP(i, 0, n - 1)
	{
		cin >> b[i];
	}
	b_max[0] = b[0];
	REP(i, 1, n - 1)
	{
		b_max[i] = max(b_max[i - 1], b[i]);
	}
	ll ans = 3 * n;
	REP(i, 0, n - 1)
	{
		ans = min(ans, i + (ll)(lower_bound(b_max.begin(), b_max.end(), a[i]) - b_max.begin()));
	}
	cout
		<< ans << "\n";
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