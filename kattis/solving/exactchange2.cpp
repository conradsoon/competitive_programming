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
#define INF 1000000000
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int p, n;
        cin >> p;
        cin >> n;
        vi v;
        v.reserve(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vi dp(10001, INF);
        vi aux(10001, 0);
        for (int i = 0; i < n; i++)
        {
            for (int i = 10000 - v[i]; i >= 0; i--)
            {
                if()
            }
        }
        cout << p + dp[p] << " " << aux[p] << "\n";
    }
    return 0;
}