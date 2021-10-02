
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
	string s;
	cin >> s;
	ll c = 0;
	int prev = -2;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
		{
			if (i != prev + 1)
			{
				c++;
			}
			prev = i;
		}
	}
	if (c == 0)
	{
		cout << "0\n";
	}
	else if (c == 1)
	{
		cout << "1\n";
	}
	else
	{
		cout << "2\n";
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