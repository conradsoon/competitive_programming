
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
const int INF = 1e9;
//template ends
void solve()
{
    int n;
    cin >> n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll x, y, r;
    ll max_x = -INF, min_x = INF, max_y = -INF, min_y = INF;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> r;
        max_x = max(max_x, x + r);
        min_x = min(min_x, x - r);
        max_y = max(max_y, y + r);
        min_y = min(min_y, y - r);
    }
    cout << (max_x - min_x) * (max_y - min_y);
    return 0;
}