#include <bits/stdc++.h>

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
typedef vector<ll> vll;
typedef vector<vll> vvll;
const int MAXITR = 20;
//template ends
vi find_indices(ull bm)
{
    vi indices;
    for (int i = 0; bm > 0; i++, bm >>= 1)
    {
        if (bm & 1)
        {
            indices.push_back(i);
        }
    }
    return indices;
};

ull compress(ull input_bm, vi &indices)
{
    ull cmp = 0;
    for (int i = 0; i < indices.size(); i++)
    {
        if (input_bm & (1ULL << indices[i]))
        {
            cmp |= 1ULL << i;
        }
    }
    return cmp;
}

ull expand(ull cmp, vi &indices)
{
    ull output_bm = 0;
    for (int i = 0; i < indices.size(); i++)
    {
        if (cmp & (1ULL << i))
        {
            output_bm |= 1ULL << indices[i];
        }
    }
    return output_bm;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, p;
    cin >> n >> m >> p;
    vector<ull> f(n);
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        //stoull(temp, &f[i], 2);
        f[i] = stoull(temp, 0, 2);
    }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> distrib(0, n - 1);
    ull mx = 0;
    for (int i = 0; i < MAXITR; i++)
    {
        int idx = distrib(rng);
        vi indices = find_indices(f[idx]);
        vector<ll> dp(1 << indices.size(), 0);
        for (int j = 0; j < n; j++)
        {
            ull bm = f[idx] & f[j];
            ull compressed_bm = compress(bm, indices);
            dp[compressed_bm]++;
        }
        //sum over superset
        for (int j = indices.size() - 1; j >= 0; j--)
        {
            for (int k = dp.size() - 1; k >= 0; k -= 1 << (indices.size() - 1 - j))
            {
                if (!(k & (1 << j)))
                {
                    dp[k] += dp[k | (1 << j)];
                }
            }
        }
        /**
        for (int j = indices.size() - 1; j >= 0; j--)
        {
            for (int k = dp.size() - 1; k >= 0; k -= 1 << (indices.size() - 1 - j))
            {
                if (!(k & (1 << j)))
                {
                    dp[k] += dp[k | (1 << j)];
                }
            }
        }
        **/
        for (int k = dp.size() - 1; k >= 0; k--)
        {
            if (dp[k] >= (n + 1) / 2)
            {
                ull exp = expand(k, indices);
                if (__builtin_popcountll(exp) > __builtin_popcountll(mx))
                {
                    mx = exp;
                }
            }
        }
    }
    cout << bitset<60>(mx).to_string().substr(60 - m, m);
    return 0;
}