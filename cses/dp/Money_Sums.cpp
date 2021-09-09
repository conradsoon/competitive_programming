
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
	vi x(n);
	ll sum = 0;
	for (auto &_x : x)
	{
		cin >> _x;
		sum += _x;
	}
	vector<bool> dp(sum + 10, false);
	dp[0] = true;
	REP(i, 0, n - 1)
	{
		REPR(j, 0, sum)
		{
			if (j + x[i] <= sum && dp[j])
			{

				dp[j + x[i]] = true;
			}
		}
	}
	ll count = 0;
	REP(i, 1, sum + 1)
	{
		if (dp[i])
		{
			count++;
		}
	}
	cout << count << "\n";
	REP(i, 1, sum + 1)
	{
		if (dp[i])
		{
			cout << i << " ";
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}