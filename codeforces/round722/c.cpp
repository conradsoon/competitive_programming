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
void solve()
{
    ll n;
    cin >> n;
    map<ll, ll> pos;
    ll temp;
    ull count = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        count += pos[temp] * (n - i);
        pos[temp] += i + 1;
    }
    cout << count << "\n";
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