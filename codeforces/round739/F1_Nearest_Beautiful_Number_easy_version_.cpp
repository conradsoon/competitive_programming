
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	set<ull> pre1;
	for (int help = 9; help >= 1; help--)
	{
		for (int i = 0; i <= 9; i++)
		{
			pre1.insert(stoll(string(help, '1')) * i);
		}
	}
	set<ull> pre2;
	for (int help = 9; help > 0; help--)
	{
		for (ll bm = (1 << help) - 1; bm >= 0; bm--)
		{
			for (int i = 0; i <= 9; i++)
			{
				for (int j = i; j <= 9; j++)
				{
					string val_str = "";
					for (int k = 0; k < help; k++)
					{
						if (bm & (1 << k))
						{
							val_str = to_string(i) + val_str;
						}
						else
						{
							val_str = to_string(j) + val_str;
						}
					}
					pre2.insert(stoll(val_str));
				}
			}
		}
	}
	pre1.insert(1111111111);
	pre2.insert(1000000000);
	int t;
	cin >> t;
	while (t--)
	{
		ull n, k;
		cin >> n >> k;
		if (k == 1)
		{
			cout << *pre1.lower_bound(n) << "\n";
		}
		else if (k == 2)
		{
			cout << *pre2.lower_bound(n) << "\n";
		}
	}
	return 0;
}