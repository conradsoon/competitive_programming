#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
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
bool is_valid(const vector<ll> &test, const vector<ll> &vals)
{
    bool valid = true;
    for (int i = 0; i < vals.size(); i++)
    {
        if (test[i] > vals[i])
        {
            valid = false;
            break;
        }
    }
    return valid;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x;
    cin >> x;
    map<ll, ll> factors = primeFactors(x);
    vector<ll> vals;
    queue<vector<ll>> q;
    ll counter = 0;

    for (auto i : factors)
    {
        vals.push_back(i.second);
    }
    sort(vals.rbegin(), vals.rend());
    q.push(vector<ll>(vals.size(), 0));
    return 0;
}