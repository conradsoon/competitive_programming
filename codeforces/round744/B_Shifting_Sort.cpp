
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <sstream>
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
	REP(i, 0, n - 1)
	{
		cin >> x[i];
	}
	vector<string> ans;
	stringstream buff;
	int count = 0;
	REP(i, 0, n - 1)
	{
		auto mitr = min_element(x.begin() + i, x.end());
		if (mitr - x.begin() != i)
		{
			buff << i + 1 << " " << n << " " << mitr - (x.begin() + i) << "\n";
			ans.push_back(buff.str());
			rotate(x.begin() + i, mitr, x.end());
			count++;
		}
	}
	cout << count << "\n";
	cout << buff.str();
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