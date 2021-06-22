
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
struct pr
{
	ll a;
	ll b;
};
bool operator<(const pr &lhs, const pr &rhs)
{
	if (lhs.b == rhs.b)
	{
		return lhs.a < rhs.a;
	}
	else
	{
		return lhs.b < rhs.b;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<pr> pdts(n);
	for (int i = 0; i < n; i++)
	{
		cin >> pdts[i].a;
		cin >> pdts[i].b;
	}
	sort(pdts.begin(), pdts.end());
	ll rubles = 0;
	ll amt = 0;
	int i = 0;
	int j = n - 1;
	while (i <= j)
	{
		if (amt >= pdts[i].b)
		{
			rubles += pdts[i].a;
			amt += pdts[i].a;
			pdts[i].a = 0;
			i++;
		}
		else
		{
			ll diffy = min(pdts[i].b - amt, pdts[j].a);
			pdts[j].a -= diffy;
			rubles += diffy * 2;
			amt += diffy;
			if (pdts[j].a == 0)
			{
				j--;
			}
		}
	}
	cout << rubles;
	return 0;
}