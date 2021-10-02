
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
	REP(i, 0, n - 1)
	{
		cin >> a[i];
	}
	//forward pass
	vi ans;
	REP(i, 0, n - 1)
	{
		int sum = a[i] + a[i + 1] + a[i + 2];
		if (sum == 2)
		{
			a[i] = 0;
			a[i + 1] = 0;
			a[i + 2] = 0;
			ans.push_back(i);
		}
	}
	REPR(i, 0, n - 3)
	{
		int sum = a[i] + a[i + 1] + a[i + 2];
		if (sum == 2)
		{
			a[i] = 0;
			a[i + 1] = 0;
			a[i + 2] = 0;
			ans.push_back(i);
		}
	}
	int sum = 0;
	REP(i, 0, n - 1)
	{
		sum += a[i];
	}
	if (sum)
	{
		cout << "NO\n";
	}
	else
	{
		cout << "YES\n";
		cout << ans.size() << "\n";
		for (auto x : ans)
		{
			cout << x + 1 << " ";
		}
		if (ans.size() != 0)
		{
			cout << "\n";
		}
	}
	//backward pass
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