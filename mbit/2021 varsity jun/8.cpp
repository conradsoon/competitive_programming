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

ll phi(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, bigJ, bigK;
    cin >> n >> bigJ >> bigK;
    vector<ld> probs(n + 1);
    vector<ll> depth(n + 1);
    depth[1] = 0;
    probs[1] = 1;
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
        }
        q.pop();
    }
    //bigJ %= M;
    //ll toh = phi(M);
    //bigK %= toh;
    ull help = mod_pow(bigJ, bigK, M);
    ull ITR = (1000 / M) * M + help;
    if (ITR >= 10000)
    {
        ITR = help;
    }
    unordered_set<int> process;
    process.insert(1);
    for (int k = 1; k <= ITR; k++)
    {
        vector<ld> temp(n + 1, 0);
        unordered_set<int> temp_process;
        for (auto i : process)
        {
            if (children[i].size() == 0)
            {
                temp[1] += probs[i];
                temp_process.insert(1);
            }
            else
            {
                ld prob = probs[i] / children[i].size();
                for (auto c : children[i])
                {
                    temp[c] += prob;
                    temp_process.insert(c);
                }
            }
        }
        swap(process, temp_process);
        swap(probs, temp);
    }
    ld expected = 0;
    for (int i = 1; i <= n; i++)
    {
        expected += probs[i] * depth[i];
    }
    cout << setprecision(16);
    cout << expected;
    //setprecision
    return 0;
}