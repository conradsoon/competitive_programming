
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
	ll a, b, c, m;
	cin >> a >> b >> c >> m;
	vll x = {a, b, c};
	sort(x.begin(), x.end());
	reverse(x.begin(), x.end());
	a = x[0];
	b = x[1];
	c = x[2];
	ll mx = a + b + c - 3;
	ll mn = 0;
	/**
	ll ab_sets = b;
	a -= abc_sets;
= abc_sets;
	c -= abc_sets;
	ll ac_sets = c;
	a -= ab_sets;
	b -= ab_sets;
	mn += max(0LL, a - abc_sets);
	**/
	if (b + c <= a + 1)
	{
		mn += a - 1;
		mn -= b + c;
		mn = max(mn, 0LL);
	}
	if (m >= mn && m <= mx)
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