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
const int MOD = 1000000000 + 7;
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll base = n;
    ll ans = 1;
    while (k)
    {
        if (k & 1)
        {
            ans = (ans * base) % MOD;
        }
        k = k >> 1;
        base = (base * base) % MOD;
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}