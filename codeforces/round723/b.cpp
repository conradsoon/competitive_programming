
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
unordered_map<ll, bool> memo;
vector<ll> to_try = {11, 111, 11111, 1111111};
bool can_make(ll n)
{
    if (memo.find(n) == memo.end())
    {
        bool b = false;
        for (int i = 3; i >= 0; i--)
        {
            if (to_try[i] > n && i != 0)
            {
                continue;
            }
            int q = n / to_try[i];
            for (int j = q; j >= 1; j--)
            {
                int tr = n - (j * to_try[i]);
                if (can_make(tr))
                {
                    b = true;
                    break;
                }
            }
        }
        memo[n] = b;
    }
    return memo[n];
}
void solve()
{
    ll n;
    cin >> n;
    cout << (can_make(n) ? "YES" : "NO") << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memo[0] = true;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}