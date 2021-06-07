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
const int MAX_ITR = 40;
void solve()
{
    int n, q;
    cin >> n >> q;
    vvi ft(3000009);
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ft[a[i]].push_back(i);
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<int> distribution(l, r);
        int max_f = -1;
        for (int i = 0; i < MAX_ITR; i++)
        {
            int t = a[distribution(generator)];
            int f = upper_bound(ft[t].begin(), ft[t].end(), r) - lower_bound(ft[t].begin(), ft[t].end(), l);
            if (f >= max_f)
            {
                max_f = f;
            }
        }
        int m = r - l + 1;
        if (max_f > (m + 1) / 2)
        {
            cout << (2 * max_f - m) << "\n";
        }
        else
        {
            cout << "1\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}