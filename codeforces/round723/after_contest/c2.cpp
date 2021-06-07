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
const ll INF = 10000000000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    multiset<ll> p;
    ll hp = 0;
    ll cnt = 0;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        if (hp + a[i] >= 0)
        {
            hp += a[i];
            cnt++;
            if (a[i] < 0)
            {
                p.insert(a[i]);
            }
        }
        else
        {
            if (!p.empty())
            {
                if (a[i] > *p.begin())
                {
                    hp -= *p.begin();
                    hp += a[i];
                    p.erase(p.begin());
                    p.insert(a[i]);
                }
            }
        }
    }
    cout << cnt;
    return 0;
}