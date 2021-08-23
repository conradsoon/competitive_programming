
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
	string t;
	cin >> t;
	map<char, int> f;
	set<char> seen;
	vector<char> last_seen;
	for (int i = t.size() - 1; i >= 0; i--)
	{
		f[t[i]]++;
		if (seen.find(t[i]) == seen.end())
		{
			seen.insert(t[i]);
			last_seen.push_back(t[i]);
		}
	}
	reverse(last_seen.begin(), last_seen.end());
	int l = 0;
	int i = 1;
	for (auto c : last_seen)
	{
		l += f[c] / i;
		i++;
	}
	string _s = t.substr(0, l);
	string _t = _s;
	for (auto op : last_seen)
	{
		string _new_s = "";
		for (auto c : _s)
		{
			if (c != op)
			{
				_new_s.push_back(c);
			}
		}
		_s = _new_s;
		_t = _t + _s;
	}
	if (_t == t)
	{
		cout << t.substr(0, l);
		cout << " ";
		for (auto c : last_seen)
		{
			cout << c;
		}
		cout << "\n";
	}
	else
	{
		cout << "-1\n";
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