
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
vector<long long> primes;

vector<long long> trial_division4(long long n)
{
	vector<long long> factorization;
	for (long long d : primes)
	{
		if (d * d > n)
			break;
		while (n % d == 0)
		{
			factorization.push_back(d);
			n /= d;
		}
	}
	if (n > 1)
		factorization.push_back(n);
	return factorization;
}
void solve()
{
	ll a, b, k;
	cin >> a >> b >> k;
	if (a > b)
	{
		swap(a, b); //wlog a<=b;
	}
	if (k == 1)
	{
		if (a == b)
		{
			cout << "NO\n";
		}
		else if (a == 1 && b != 1)
		{
			cout << "YES\n";
		}
		else if (a != 1)
		{
			if (a * (b / a) == b)
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
	else
	{
		vll a_fact = trial_division4(a);
		vll b_fact = trial_division4(b);
		if (k <= a_fact.size() + b_fact.size())
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
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

	const ll N = 105000;
	int lp[N + 1];

	for (ll i = 2; i <= N; ++i)
	{
		if (lp[i] == 0)
		{
			lp[i] = i;
			primes.push_back(i);
		}
		for (ll j = 0; j < (ll)primes.size() && primes[j] <= lp[i] && i * primes[j] <= N; ++j)
			lp[i * primes[j]] = primes[j];
	}

	while (t--)
	{
		solve();
	}
	return 0;
}