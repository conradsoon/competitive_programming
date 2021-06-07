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
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> b[i];
    }
    vector<ll> mas(n, 0);          //money at start of job
    vector<ll> d(n, 0);            //days to promote
    vector<ll> cd(n, 0);           //days to get computerino
    cd[0] = (c + a[0] - 1) / a[0]; ///hard code cus im lazy
    for (ll i = 1; i < n; i++)
    {
        ll ttp = (b[i - 1] - mas[i - 1] + a[i - 1] - 1) / a[i - 1]; //ceil div
        d[i] = d[i - 1] + ttp + 1;
        mas[i] = a[i - 1] * ttp + mas[i - 1] - b[i - 1];
        cd[i] = (c - mas[i] + a[i] - 1) / a[i] + d[i];
    }
    cout << *min_element(cd.begin(), cd.end()) << "\n";
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