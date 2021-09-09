
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
	string s;
	cin >> s;
	vi ones;
	vi twos;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '1')
		{
			ones.push_back(i);
		}
		else
		{
			twos.push_back(i);
		}
	}
	vector<string> r(n, string(n, '='));
	for (int i = 0; i < n; i++)
	{
		r[i][i] = 'X';
	}
	if (twos.size() == 1 || twos.size() == 2)
	{
		cout << "NO\n";
		return;
	}
	else if (twos.size() != 0)
	{
		for (int i = 0; i < twos.size(); i++)
		{
			r[twos[i]][twos[(i + 1) % twos.size()]] = '+';
			r[twos[(i + 1) % twos.size()]][twos[i]] = '-';
		}
	}
	cout << "YES\n";
	for (auto row : r)
	{
		cout << row << "\n";
	}
	/**
	for (int i = 0; i < ones.size(); i++)
	{
		for (int j = i + 1; j < ones.size(); j++)
		{
			r[i][j] = '=';
			r[j][i] = '=';
		}
	}
	**/
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