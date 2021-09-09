
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
#define REP(i, a, b) for (int i = a; i < b; i++)
//template ends
const int INF = 1e17;
void solve()
{
	string s1, s2;
	cin >> s1 >> s2;
	vvll dp(s1.size() + 1, vll(s2.size() + 1, INF));
	dp[0][0] = 0;
	REP(i, 1, s1.size() + 1)
	{
		REP(j, 1, s2.size() + 1)
		{
			dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (ll)(s1[i - 1] != s2[j - 1]));
			dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
		}
	}
	cout << dp[s1.size()][s2.size()] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}