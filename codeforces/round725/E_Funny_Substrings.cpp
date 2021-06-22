
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
struct Word
{
	string pfx = "";
	string sfx = "";
	ll no = 0;
};

ll count_haha(string s)
{
	int no_haha = 0;
	if (s.length() >= 4)
	{
		for (int i = 0; i + 4 <= s.length(); i++)
		{
			if (s.substr(i, 4) == "haha")
			{
				no_haha++;
			}
		}
	}
	return no_haha;
}

void solve()
{
	int n;
	cin >> n;
	string var;
	string opr;
	cin >> var >> opr;
	map<string, Word> mem;
	if (opr == ':=')
	{
		string s;
		cin >> s;
		for (int i = 0; i < min(s.length(), 3); i++)
		{
			mem[var].pfx.push_back(s[i]);
			mem[var].sfx.push_back(s[n - 1 - i]);
			mem[var].no = count_haha(s);
		}
	}
	else if (opr == '=')
	{
		string var1, nonce, var2;
		cin >> var1 >> nonce >> var2;
		Word temp = mem[var];
		temp.pfx = mem[var1].pfx;
		temp.sfx = mem[var2].sfx;
		temp.no = mem[var1].no + mem[var2].no;
		temp.no += count_haha(var1.sfx + var2.pfx);
		if (temp.pfx.length() < 3)
		{
			temp.pfx += var1.
		}
		if (temp.sfx.length() < 3)
		{
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