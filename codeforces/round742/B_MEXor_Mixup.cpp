
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
ll oeis(ll n)
{
	int mod = n % 4;
	if (n == 0)
	{
		return 0;
	}
	if (mod == 1)
	{
		return 1;
	}
	else if (mod == 2)
	{
		return n + 1;
	}
	else if (mod == 3)
	{
		return 0;
	}
	else
	{
		return n;
	}
}
void solve()
{
	ll a, b;
	cin >> a >> b;
	ll o = oeis(a - 1);
	ll req = o ^ b;
	if (req == 0)
	{
		cout << a;
	}
	else
	{
		if (req == a)
		{
			cout << a + 2;
		}
		else
		{
			cout << a + 1;
		}
	}
	/**
	if (b < o)
	{
		cout << a + 1;
	}
	else if (b == o)
	{
		cout << a;
	}
	else if (b - o == 1)
	{
		cout << a + 2;
	}
	else
	{
		cout << a + 1;
	}
	**/
	cout << "\n";
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