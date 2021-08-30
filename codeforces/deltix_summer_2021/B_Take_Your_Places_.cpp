
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

//https://www.geeksforgeeks.org/minimum-swaps-required-to-make-a-binary-string-alternating/
void solve()
{
	int n;
	cin >> n;
	int odd_num = 0;
	int even_num = 0;
	vi a(n);
	vi odd_idx;
	vi even_idx;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] % 2)
		{
			odd_idx.push_back(i);
			odd_num++;
		}
		else
		{
			even_idx.push_back(i);
			even_num++;
		}
	}
	if (abs(odd_num - even_num) > 1)
	{
		cout << "-1\n";
	}
	else
	{
		ll count = 0;
		if (n % 2)
		{
			if (odd_num > even_num)
			{
				for (int i = 0; i < odd_num; i++)
				{
					count += abs((2 * i) - odd_idx[i]);
				}
			}
			else
			{
				for (int i = 0; i < even_num; i++)
				{
					count += abs((2 * i) - even_idx[i]);
				}
			}
		}
		else
		{
			ll count1 = 0;
			for (int i = 0; i < odd_num; i++)
			{
				count1 += abs((2 * i) - odd_idx[i]);
			}
			ll count2 = 0;
			for (int i = 0; i < even_num; i++)
			{
				count2 += abs((2 * i) - even_idx[i]);
			}
			count = min(count1, count2);
		}
		cout << count << "\n";
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