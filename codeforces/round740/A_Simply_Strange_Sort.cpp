
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
bool isSorted(vi &a)
{
	bool sorted = true;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != i + 1)
		{
			sorted = false;
			break;
		}
	}
	return sorted;
}
void f(int i, vi &a)
{
	if (a[i] > a[i + 1])
	{
		swap(a[i], a[i + 1]);
	}
}
void solve()
{
	int n;
	cin >> n;
	vi a(n);
	for (auto &x : a)
	{
		cin >> x;
	}
	int counter = 0;
	while (!isSorted(a))
	{
		counter++;
		if (counter % 2)
		{
			for (int i = 0; i < a.size() - 1; i += 2)
			{
				f(i, a);
			}
		}
		else
		{
			for (int i = 1; i < a.size(); i += 2)
			{
				f(i, a);
			}
		}
	}
	cout << counter << "\n";
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