#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <math.h>
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
ld price(int p, int a, int b, int c, int d, int k)
{
    return (ld)p * (sin(a * k + b) + cos(c * k + d) + 2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p, a, b, c, d, n;
    cin >> p >> a >> b >> c >> d >> n;
    vector<ld> diff;
    diff.reserve(n);
    for (int i = 2; i <= n; i++)
    {
        diff.push_back(-(price(p, a, b, c, d, i) - price(p, a, b, c, d, i - 1)));
    }
    ld best = 0;
    ld sum = 0;
    for(int k = 0; k < diff.size(); k++){
        sum = max(diff[k], sum+diff[k]);
        best = max(best,sum);
    }
    cout << setprecision(16) << best << "\n";
    return 0;
}