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

//template ends
//https://codeforces.com/blog/entry/72047
#define MOD 1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll r, c;
        cin >> r >> c;
        ll n = 1;
        for (ll i = 0; i < r; i++)
        {
            n = (n * 3) % MOD;
        }
        for (ll i = 0; i < c; i++)
        {
            n = (n * 3) % MOD;
        }
        for (ll i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                n = (n * 2) % MOD;
            }
        }
        cout << n << "\n";
    }
    return 0;
}