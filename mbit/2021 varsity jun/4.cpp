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
const ull MOD = 10e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ull n, k;
    cin >> n >> k;
    vector<ull> t(19, 1);
    t[1] = 2;
    for (int i = 2; i <= 19; i++)
    {
        t[i] = t[i - 1] * t[i - 1];
        t[i] %= MOD;
    }
    n++;
    ull lg2c = ceill(log2((ld)n));
    ull exp = n - 1 - lg2c;
    int i = 0;
    ull res = 1;
    while (exp > 0)
    {
        if (exp & 1)
        {
            res *= t[i + 1];
            res %= MOD;
        }
        exp >>= 1;
        i++;
    }

    //check if k > n
    k = k + 1;
    //k = min(res, k);
    cout << (res * (k % MOD)) % MOD;
    return 0;
}