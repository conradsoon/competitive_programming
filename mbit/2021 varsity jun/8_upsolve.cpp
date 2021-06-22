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

ull mod_pow(ull num, ull pow, ull mod)
{
    unsigned long long test;
    unsigned long long n = num;
    for (test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = ((test % mod) * (n % mod)) % mod;
        n = ((n % mod) * (n % mod)) % mod;
    }

    return test; /* note this is potentially lossy */
}

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, bigJ, bigK;
    cin >> n >> bigJ >> bigK;
    vector<ll> depth(n + 1);
    vector<ld> k(n + 1);
    depth[1] = 0;
    k[1] = 1;
    vvi children(n + 1);
    ll M = -1;
    int a, b;
    for (int i = 1; i < n; i++) //tree has n-1 edges
    {
        cin >> a >> b;
        children[a].push_back(b);
    }
    //dfs to find depth
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        if (children[q.front()].size() == 0)
        {
            if (M == -1)
            {
                M = depth[q.front()] + 1;
            }
            else
            {
                M = __gcd(M, depth[q.front()] + 1);
            }
        }
        for (auto c : children[q.front()])
        {
            depth[c] = depth[q.front()] + 1;
            q.push(c);
            k[c] = k[q.front()] / children[q.front()].size();
        }
        q.pop();
    }
    //bigJ %= M;
    //ll toh = phi(M);
    //bigK %= toh;
    ull help = mod_pow(bigJ, bigK, M);
    ld k_sum = 0;
    for (int i = 1; i <= n; i++)
    {
        k_sum += k[i];
    }
    ld expected = 0;
    for (int i = 1; i <= n; i++)
    {
        if (depth[i] % M == help)
        {
            expected += k[i] / k_sum * depth[i];
        }
    }
    expected *= M;
    cout << setprecision(16);
    cout << expected;
    //setprecision
    return 0;
}