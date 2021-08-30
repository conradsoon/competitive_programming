
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
bool isSubarray(string s, string sub)
{
	bool substringFound = false;
	for (int i = 0; i < s.size() - 1 && !substringFound; i++)
	{
		if (s[i] == sub[0])
		{
			for (int j = i + 1; j < s.size(); j++)
			{
				if (s[j] == sub[1])
				{

					substringFound = true;
					break;
				}
			}
		}
	}
	return substringFound;
}
void solve()
{
	int k;
	cin >> k;
	string n;
	cin >> n;
	vi freq(10);
	vector<string> brute = {"22", "25", "27", "32", "33", "35", "52", "55", "57", "72", "75", "77"};
	for (auto c : n)
	{
		freq[c - '0']++;
	}
	bool hasNonPrimeDig = false;
	int nonPrimeDig;
	if (freq[1])
	{
		hasNonPrimeDig = true;
		nonPrimeDig = 1;
	}
	if (freq[4])
	{
		hasNonPrimeDig = true;
		nonPrimeDig = 4;
	}
	if (freq[6])
	{
		hasNonPrimeDig = true;
		nonPrimeDig = 6;
	}
	if (freq[8])
	{
		hasNonPrimeDig = true;
		nonPrimeDig = 8;
	}
	if (freq[9])
	{
		hasNonPrimeDig = true;
		nonPrimeDig = 9;
	}
	if (hasNonPrimeDig)
	{
		cout << "1\n"
			 << nonPrimeDig << "\n";
	}
	else
	{
		if (n.size() <= 2)
		{
			cout << n.size() << "\n"
				 << n << "\n";
		}
		else
		{
			for (auto s : brute)
			{
				if (isSubarray(n, s))
				{
					cout << "2\n"
						 << s << "\n";
					break;
				}
			}
		}
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