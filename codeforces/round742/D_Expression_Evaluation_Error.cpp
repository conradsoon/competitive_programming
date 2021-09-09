
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
	string s_str;
	ll n;
	cin >> s_str >> n;
	ll s = stoll(s_str);
	reverse(s_str.begin(), s_str.end());
	vll f(10, 0);
	vll p(10, 0);
	p[0] = 1;
	for (int i = 1; i < 10; i++)
	{
		p[i] = p[i - 1] * 10;
	}
	ll powsum = 0;
	for (int i = 0; i < s_str.size(); i++)
	{
		f[i] = s_str[i] - '0';
		powsum += f[i];
	}
	while (powsum < n)
	{
		int j = 1;
		while (f[j] == 0)
		{
			j++;
		}
		f[j]--;
		powsum--;
		f[j - 1] += 10;
		powsum += 10;
	}
	vll x(n);
	int i = 0;
	int j = 0;
	while (powsum)
	{
		while (f[j] == 0)
		{
			j++;
		}
		x[i] += p[j];
		f[j]--;
		i++;
		i %= n;
		powsum--;
	}
	for (auto _x : x)
	{
		cout << _x << " ";
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