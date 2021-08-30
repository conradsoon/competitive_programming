
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
	string s;
	cin >> s;
	queue<int> q;
	if (s == string(s.size(), '?'))
	{
		s[0] = 'R';
	}
	for (int i = 0; i < n; i++)
	{
		q.push(i);
	}
	while (!q.empty())
	{
		int f = q.front();
		q.pop();
		if (s[f] != '?')
		{
			if (f > 0)
			{
				if (s[f - 1] == '?')
				{
					if (s[f] == 'R')
					{
						s[f - 1] = 'B';
					}
					else
					{
						s[f - 1] = 'R';
					}
					q.push(f - 1);
				}
			}
			if (f < n - 1)
			{
				if (s[f + 1] == '?')
				{
					if (s[f] == 'R')
					{
						s[f + 1] = 'B';
					}
					else
					{
						s[f + 1] = 'R';
					}
				}
				q.push(f + 1);
			}
		}
	}
	cout << s << "\n";
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