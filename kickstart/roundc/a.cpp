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
const ll MOD = 1000000007;
void solve(int tc)
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll count = 1;
    ll base = 1;
    for (int i = (n + 1) / 2 - 1; i >= 0; i--)
    {
        count += base * (s[i] - 'a');
        count = count % (MOD);
        base = base * k;
        base = base % MOD;
    }
    string palin_s = s;
    for (int i = 0; i < n / 2; i++)
    {
        palin_s[n - i - 1] = palin_s[i];
    }
    if (palin_s >= s)
    {
        count--;
        count = (count + MOD) % MOD;
    }
    cout << "Case #" << tc << ": " << count << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve(tc);
    }
    return 0;
}