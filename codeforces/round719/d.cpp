#include <bits/stdc++.h>
#include <unordered_map>
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
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        unordered_map<ll, ll> a;
        ll temp;
        for (ll i = 0; i < n; i++)
        {
            cin >> temp;
            a[temp - i]++;
        }
        ll count = 0;
        for (auto kv : a)
        {
            count += (kv.second * (kv.second - 1)) / 2;
        }
        cout << count << "\n";
    }
    return 0;
}