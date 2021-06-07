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
//template ends
const int N = 1000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int lp[N + 1];
    vector<int> pr;
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
    int t;
    cin >> t;
    for (int holyshitiwanttodie = 1; holyshitiwanttodie <= t; holyshitiwanttodie++)
    {
        ll g;
        cin >> g;
        g *= 2;
        ll saved_g = g;
        map<ll, ll> factors;
        for (long long d : pr)
        {
            if (d * d > g)
                break;
            while (g % d == 0)
            {
                factors[d]++;
                g /= d;
            }
        }
        if (g > 1)
            factors[g]++;
        ull count = 0;
        unordered_set<ll> dvsrs;
        dvsrs.insert(1);
        for (auto kv : factors)
        {
            vector<ll> gen;
            ll abc = 1;
            for (int i = 0; i <= kv.second; i++)
            {
                for (auto killme : dvsrs)
                {
                    gen.push_back(killme * abc);
                }
                abc *= kv.first;
            }
            for (auto help : gen)
            {
                dvsrs.insert(help);
            }
        }
        for (auto fd : dvsrs)
        {
            ll gdf = (saved_g / fd) + 1 - fd;
            if (gdf % 2 == 0 && gdf > 0)
            {
                count++;
            }
        }
        cout << "Case #" << holyshitiwanttodie << ": " << count << "\n";
    }
    return 0;
}