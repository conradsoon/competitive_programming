
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
	ll c, d;
	cin >> c >> d;
	if (c > d)
	{
		swap(c, d);
	}
	if (c == 0 && d == 0)
	{
		cout << "0\n";
		return;
	}
	if (c == d)
	{
		cout << "1\n";
		return;
	}
	if ((d - c) % 2)
	{
		cout << "-1\n";
		return;
	}
	else
	{
		cout << "2\n";
		return;
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