
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
void solve(ll casenum)
{
    ll a, b, c, d, f, g, h, i;
    cin >> a >> b >> c >> d >> f >> g >> h >> i;
    ll count = 0;
    if (a - b == b - c)
    {
        count++;
    }
    if (c - f == f - i)
    {
        count++;
    }
    if (a - d == d - g)
    {
        count++;
    }
    if (g - h == h - i)
    {
        count++;
    }
    map<ll, ll> nums;
    if ((a - i) % 2 == 0)
    {
        nums[a + ((i - a) / 2)]++;
    }
    if ((c - g) % 2 == 0)
    {
        nums[c + ((g - c) / 2)]++;
    }
    if ((b - h) % 2 == 0)
    {
        nums[b + ((h - b) / 2)]++;
    }
    if ((f - d) % 2 == 0)
    {
        nums[d + ((f - d) / 2)]++;
    }
    ll m = 0;
    for (auto kv : nums)
    {
        m = max(m, kv.second);
    }
    count += m;
    cout << "Case #" << casenum << ": " << count << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve(i);
    }
    return 0;
}