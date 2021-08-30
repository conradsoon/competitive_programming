#include <iostream>
#include <string>
#include <vector>

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
void solve()
{
    cin.ignore();
    ull n;
    cin >> n;
    ull c;
    ull sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        sum = (sum + (c % n)) % n;
    }
    cout << (sum == 0 ? "YES\n" : "NO\n");
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}