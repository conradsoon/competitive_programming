#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    for (ll tc = 1; tc < t + 1; tc++)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<ll>());
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            sum += a[i] * b[i];
        }
        cout << "Case #" << tc << ": " << sum << "\n";
    }
    return 0;
}