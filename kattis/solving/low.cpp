#include <iostream>
#include <string>
#include <vector>
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
const int INF = 2000000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vi b(2 * n * k);
    for (int i = 0; i < 2 * n * k; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    int d = b[1] - b[0];
    int min_d = INF;
    for (int i = 3; i < 2 * n * k; i += 2)
    {
        min_d = min(min_d, b[i] - b[i - 1]);
    }
    cout << max(d, min_d);
    return 0;
}