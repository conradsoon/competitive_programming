
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
	ll n;
	cin >> n;
	ll lb = floorl(sqrt((ld)n));
	ll r = n - (lb * lb);
	if (r == 0)
	{
		cout << lb << " "
			 << "1"
			 << "\n";
	}
	else if (r <= lb)
	{
		cout << r << " " << lb + 1 << "\n";
	}
	else if (r == lb + 1)
	{
		cout << lb + 1 << " " << lb + 1 << "\n";
	}
	else
	{
		cout << lb + 1 << " " << (lb + 1) - (r - (lb + 1)) << "\n";
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