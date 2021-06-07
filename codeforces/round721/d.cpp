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
const ll INF = 1e8;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<bool> oc(n, false);
    vector<ll> a;
    ll t;
    for (ll i = 0; i < n; i++)
    {
        cin >> t;
        if (t == 1)
        {
            a.push_back(i);
            oc[i] = true;
        }
    }
    ll cnt = 0;
    for (auto p : a)
    {
        ll l; //check if its at side how
        bool l_found = false;
        for (ll i = p - 1; i >= 0; i--)
        {
            if (oc[i] == false)
            {
                l = i;
                l_found = true;
                break;
            }
        }
        ll r;
        bool r_found = false;
        for (ll i = p + 1; i < n; i++)
        {
            if (oc[i] == false)
            {
                r = i;
                r_found = true;
                break;
            }
        }
        if (r_found && l_found)
        {

            if (abs(p - l) <= abs(r - p))
            {

                oc[l] = true;
                cnt += abs(p - l);
            }
            else
            {
                oc[r] = true;
                cnt += abs(r - p);
            }
        }
        else if (r_found)
        {
            oc[r] = true;
            cnt += abs(r - p);
        }
        else if (l_found)
        {
            oc[l] = true;
            cnt += abs(p - l);
        }
    }
    cout << cnt;
    return 0;
}