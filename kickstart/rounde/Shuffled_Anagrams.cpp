
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
void solve(int n)
{
	string s;
	cin >> s;
	map<char, int> mp;
	for (auto c : s)
	{
		mp[c]++;
	}
	vector<pair<int, char>> f;
	for (auto kv : mp)
	{
		f.push_back({kv.second, kv.first});
	}
	sort(f.begin(), f.end());
	reverse(f.begin(), f.end());
	if (f[0].first <= s.size() / 2)
	{
		string _s = string(s.size(), 'X');
		for (int i = 0; i < f.size(); i++)
		{
			int k = (i + 1) % f.size();
			for (int j = 0; j < s.size(); j++)
			{
				if (s[j] == f[i].second)
				{
					while (f[k].first == 0)
					{
						k += 1;
						k %= f.size();
					}
					f[k].first--;
					_s[j] = f[k].second;
				}
			}
		}
		cout << "Case #" << n << ": " + _s << "\n";
	}
	else
	{
		cout << "Case #" << n << ": IMPOSSIBLE\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		solve(i);
	}
	return 0;
}