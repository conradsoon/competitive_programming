
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
bool check(string s, string _s)
{
	bool isOk = true;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == _s[i])
		{
			isOk = false;
			break;
		}
	}
	return isOk;
}
void solve(int n)
{
	string s;
	cin >> s;
	map<char, vi> p;
	for (int i = 0; i < s.size(); i++)
	{
		p[s[i]].push_back(i);
	}
	bool isPossible = true;
	for (auto kv : p)
	{
		if (kv.second.size() > s.length() / 2)
		{
			isPossible = false;
		}
	}
	if (isPossible)
	{
		vvi groups;
		vector<bool> used(s.size(), false);
		for (int i = 0; i < s.size(); i++)
		{
			if (!used[i])
			{
				used[i] = true;
				for (int j = i; j < s.size(); j++)
				{
					if (!used[j])
					{
						groups.push_back({i, j});
						used[j] = true;
						break;
					}
				}
			}
		}
		if (s.size() % 2 == 1)
		{
			for (int i = 0; i < groups.size(); i++)
			{
				bool pos = true;
				for (auto idx : groups[i])
				{
					if (s[idx] == s.back())
					{
						pos = false;
						break;
					}
				}
				if (pos)
				{
					groups[i].push_back(s.size() - 1);
					break;
				}
			}
		}
		for (auto g : groups)
		{
			for (int i = 0; i < g.size() - 1; i++)
			{
				swap(s[g[i]], s[g[i + 1]]);
			}
		}
		cout << "Case #" << n << ": " << s << "\n";
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