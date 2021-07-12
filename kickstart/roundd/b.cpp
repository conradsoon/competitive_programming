
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
    ll n, c;
    cin >> n >> c;
    ll temp1, temp2;
    map<ll, ll> m;
    for (int i = 0; i < n; i++)
    {
        cin >> temp1 >> temp2;
        m[temp1 + 1]++;
        m[temp2]--;
    }
    ll j = (*m.begin()).second;
    map<ll, ll> cuts;
    ll prev = (*m.begin()).first;
    ll curr;
    for (auto it = ++m.begin(); it != m.end(); it++)
    {
        curr = (*it).first;
        cuts[j] += curr - prev;
        prev = curr;
        j += (*it).second;
    }
    ull count = n;
    for (auto it = cuts.rbegin(); it != cuts.rend() && c > 0; it++)
    {
        if (c >= (*it).second)
        {
            count += (*it).second * (*it).first;
            c -= (*it).second;
        }
        else
        {
            count += (*it).first * c;
            c -= c;
        }
    }
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