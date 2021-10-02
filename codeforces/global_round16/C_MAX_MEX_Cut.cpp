
#include <bits/stdc++.h>

using namespace std;

//TYPEDEFS
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

//MACROS
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define REPR(i, a, b) for (int i = b; i >= a; i--)
//template ends
void solve()
{
	int n;
	string s1;
	string s2;
	cin >> n >> s1 >> s2;
	ll count = 0;
	bool prev = false;
	char prev_num = 'x';
	for (int i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			count += 2;
			if (prev)
			{
				if (prev_num == '0')
				{
					count++;
				}
			}
			prev = false;
		}
		else
		{
			if (s1[i] == '0')
			{
				if (prev)
				{
					if (prev_num == '0')
					{
						count += 1;
					}
					else
					{
						count += 2;
						prev = false;
					}
				}
				else
				{
					prev = true;
					prev_num = '0';
				}
			}
			else
			{
				if (prev)
				{
					if (prev_num == '0')
					{
						count += 2;
						prev = false;
					}
				}
				else
				{
					prev = true;
					prev_num = '1';
				}
			}
		}
	}
	if (prev)
	{
		if (prev_num == '0')
		{
			count++;
		}
	}
	cout << count << "\n";
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