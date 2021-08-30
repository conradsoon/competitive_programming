#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
//template ends
map<ll, ll> primeFactors(ll n)
{
    map<ll, ll> fac;
    for (ll i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            n /= i;
            fac[i]++;
        }
    }
    if (n > 1)
    {
        fac[n]++;
    }
    return fac;
}

bool legendre(ll n, ll p, ll min_req)
{
    ll sum = 0;
    while (n > 0)
    {
        n /= p;
        sum += n;
        if (sum >= min_req)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    while (cin >> n >> m)
    {
        bool is_divisible = true;
        map<ll, ll> factors = primeFactors(m);
        for (auto p : factors)
        {
            if (!legendre(n, p.first, p.second))
            {
                is_divisible = false;
                break;
            }
        }
        if (is_divisible)
        {
            cout << m << " divides " << n << "!" << endl;
        }
        else
        {
            cout << m << " does not divide " << n << "!" << endl;
        }
    }
    return 0;
}