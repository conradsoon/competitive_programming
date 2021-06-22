
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ull n, k, x;
	cin >> n >> k >> x;
	vector<ull> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<ull> d;
	for (int i = 1; i < n; i++)
	{
		ull diff = a[i] - a[i - 1];
		if (diff > x)
		{
			d.push_back((diff - 1) / x);
		}
	}
	sort(d.begin(), d.end());
	ull ptn = d.size() + 1;
	for (int i = 0; i < d.size(); i++)
	{
		if (k < d[i])
		{
			break;
		}
		else
		{
			k -= d[i];
			ptn--;
		}
	}
	cout << ptn;
	return 0;
}