
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
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<vector<ull>> freq_table(26, vector<ull>(n, 0));
	freq_table[s[0] - 'a'][0]++;
	for (int i = 1; i < n; i++)
	{
		for (int k = 0; k < 26; k++)
		{
			freq_table[k][i] = freq_table[k][i - 1];
		}
		freq_table[s[i] - 'a'][i]++;
	}
	for (int i = 0; i < q; i++)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		ull count = 0;
		for (int k = 0; k < 26; k++)
		{
			count += freq_table[k][r] * (k + 1);
			if (l > 0)
			{
				count -= freq_table[k][l - 1] * (k + 1);
			}
		}
		cout << count << "\n";
	}
	return 0;
}