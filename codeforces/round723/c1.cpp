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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    vector<ll> b;
    ll hp = 0;
    ll cnter = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < 0)
        {
            b.push_back(-1 * a[i]);
        }
        else
        {
            hp += a[i];
            cnter++;
        }
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < b.size(), hp - b[i] >= 0; hp -= b[i], cnter++, i++)
    {
        //test
    }
    cout << cnter;
    return 0;
}