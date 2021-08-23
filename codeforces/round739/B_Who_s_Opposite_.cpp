
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

//template ends
void solve()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b)
	{
		swap(a, b); //WLOG a<=b;
	}
	int diff = b - a;
	if (a > diff)
	{
		//cannot be opposite
		cout << "-1\n";
	}
	else
	{
		if (c > diff * 2)
		{
			cout << "-1\n";
		}
		else
		{
			int ans = c + diff;
			if (ans > diff * 2)
			{
				ans -= diff * 2;
			}
			cout << ans << "\n";
		}
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