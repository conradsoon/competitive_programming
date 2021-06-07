#include <bits/stdc++.h>
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
struct rc
{
    ll r;
    ll c;
};
bool operator<(const rc &a, const rc &b)
{
    if (a.r == b.r)
    {
        return a.c < b.c;
    }
    else
    {
        return a.r < b.r;
    }
}
ll family(const rc &a)
{
    return (a.r - a.c) / 2;
}
void solve()
{
    ll n;
    cin >> n;
    vector<rc> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].r;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].c;
    }
    a.push_back({1, 1});
    sort(a.begin(), a.end());
    ll min_num = 0;
    for (int i = 0; i < n; i++)
    {
        //check if same family. if same family need check seed
        ll fam1 = family(a[i]);
        ll fam2 = family(a[i + 1]);
        ll sum1 = a[i].c + a[i].r;
        ll sum2 = a[i + 1].c + a[i + 1].r;
        if (fam1 == fam2 && sum1 % 2 == 0 && sum2 % 2 == 0)
        {
            min_num += (sum2 - sum1) / 2;
        }
        else
        {
            min_num += fam2 - fam1;
        }
    }
    cout << min_num << "\n";
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