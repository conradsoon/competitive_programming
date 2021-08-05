
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
	int n;
	cin >> n;
	vi a(n);
	set<int> seen;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		seen.insert(a[i]);
	}
	map<int, int> orig_even_parity;
	map<int, int> orig_odd_parity;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 1)
		{
			orig_odd_parity[a[i]]++;
		}
		else
		{

			orig_even_parity[a[i]]++;
		}
	}
	sort(a.begin(), a.end());
	map<int, int> end_even_parity;
	map<int, int> end_odd_parity;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 1)
		{
			end_odd_parity[a[i]]++;
		}
		else
		{

			end_even_parity[a[i]]++;
		}
	}
	bool ok = true;
	for (auto i : seen)
	{
		if (orig_even_parity[i] != end_even_parity[i] || orig_odd_parity[i] != end_odd_parity[i])
		{
			ok = false;
			break;
		}
	}
	if (ok)
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