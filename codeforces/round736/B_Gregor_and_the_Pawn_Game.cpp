
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
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	ll count = 0;
	ll pawn_count = 0;
	vector<bool> state(n, false);
	REP(i, 0, n - 1)
	{
		if (s1[i] == '1')
		{
			state[i] = true;
		}
	}
	REP(i, 0, n - 1)
	{
		if (s2[i] == '1')
		{
			if (s1[i] == '0')
			{
				count++;
			}
			else
			{
				if (i - 1 >= 0 && state[i - 1])
				{
					state[i - 1] = false;
					count++;
				}
				else if (i + 1 <= n - 1 && state[i + 1])
				{
					state[i + 1] = false;
					count++;
				}
			}
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