#include <iostream>
#include <string>
#include <vector>
#include <math.h>
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
const int INF = 2000000000;
vector<long long> trial_division2(long long n)
{
    vector<long long> factorization;
    while (n % 2 == 0)
    {
        factorization.push_back(2);
        n /= 2;
    }
    for (long long d = 3; d * d <= n; d += 2)
    {
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    while (cin >> n && n != 0)
    {
        if (n <= 6)
        {
            if (n == 3)
            {
                cout << 4 << "\n";
            }
            else
            {
                cout << "No such base\n";
            }
        }
        else
        {
            vector<ll> factor = trial_division2(n - 3);
            ll best = INF;
            auto it = upper_bound(factor.begin(), factor.end(), 3);
            if (it != factor.end())
            {
                best = *it;
            }
            if (factor.size() >= 2)
            {
                best = min(best, factor[0] * factor[1]);
            }
            cout << best << "\n";
        }
    }
    return 0;
}