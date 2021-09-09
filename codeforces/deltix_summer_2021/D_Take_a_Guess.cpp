
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
void solve()
{
    int n, k;
    cin >> n >> k;
    ll o12, o23, o13;
    ll a12, a23, a13;
    cout << "or 1 2"
         << "\n";
    fflush(stdout);
    cin >> o12;
    cout << "or 2 3"
         << "\n";
    fflush(stdout);
    cin >> o23;
    cout << "or 1 3"
         << "\n";
    fflush(stdout);
    cin >> o13;
    cout << "and 1 2"
         << "\n";
    fflush(stdout);
    cin >> a12;
    cout << "and 2 3"
         << "\n";
    fflush(stdout);
    cin >> a23;
    cout << "and 1 3"
         << "\n";
    fflush(stdout);
    cin >> a13;
    ll a_1;
    a_1 = (o12 + a12 + o23 + a23 + o13 + a13) / 2 - (o23 + a23);
    vll a;
    a.push_back(a_1);
    a.push_back(o12 + a12 - a_1);
    a.push_back(o13 + a13 - a_1);
    for (int i = 4; i <= n; i++)
    {
        ll temp_o;
        cout << "or 1 " << i
             << "\n";
        fflush(stdout);
        cin >> temp_o;
        ll temp_a;
        cout << "and 1 " << i
             << "\n";
        fflush(stdout);
        cin >> temp_a;
        a.push_back(temp_o + temp_a - a_1);
    }
    sort(a.begin(), a.end());
    cout << "finish " << a[k - 1] << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}