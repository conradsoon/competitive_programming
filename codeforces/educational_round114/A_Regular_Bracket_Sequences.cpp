
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	vector<vector<string>> s(51);
	s[1].push_back("()");
	REP(i, 2, 50)
	{
		for (auto x : s[i - 1])
		{
			if (s[i].size() >= i)
			{
				break;
			}
			s[i].push_back(x + "()");
			s[i].push_back("(" + x + ")");
		}
	}
	while (t--)
	{
		int n;
		cin >> n;
		REP(i, 0, n - 1)
		{
			cout << s[n][i] << "\n";
		}
	}
	return 0;
}