
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
	int a, b;
	cin >> a >> b;
	set<int> k;
	//wlog let a be the bigger one.
	if (a < b)
	{
		swap(a, b);
	}
	//ABAB
	int s_1 = a - ((a + b + 1) / 2);
	for (int i = 0; i <= b; i++)
	{
		k.insert(s_1 + i * 2);
	}
	//BABA
	int s_2 = a - ((a + b) / 2);
	for (int i = 0; i <= b; i++)
	{
		k.insert(s_2 + i * 2);
	}
	cout << k.size() << "\n";
	for (auto c : k)
	{
		cout << c << " ";
	}
	cout << "\n";
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