#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <numeric>
#include <math.h>
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
vector<ld> d;
vector<ld> r;
ld d_sum;
ld r_sum;
ld t;
//newton's method might have numerical stability issues but i cant be fucked to debug it
/**
ld drv(ld c)
{
    ld sum = 0;
    for (int i = 0; i < d.size(); i++)
    {
        sum += (d[i]) / pow((r[i] + c), 2);
    }
    return sum;
}
**/
ld fnc(ld c)
{
    ld sum = 0;
    sum += t;
    for (int i = 0; i < d.size(); i++)
    {
        sum -= (d[i]) / (r[i] + c);
    }
    return sum;
}
/**
ld iter_newton(ld c)
{
    return c - (fnc(c) / drv(c));
}
**/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cin >> t;
    while (n--)
    {
        ld a, b;
        cin >> a >> b;
        d.push_back(a);
        r.push_back(b);
    }
    d_sum = accumulate(d.begin(), d.end(), 0);
    r_sum = accumulate(r.begin(), r.end(), 0);
    ld lo_bound = -(*min_element(r.begin(), r.end())); //c has a lower bound of the -smallest reading, because actual speed cannot be less than zero.
    ld hi_bound = 100000000000000;
    ld mid;
    ld min_diff_until_terminate = 0.000000000001;
    int max_iter = 250;
    int iter = 0;
    while (abs(lo_bound - hi_bound) > min_diff_until_terminate && iter < max_iter)
    {
        mid = (lo_bound + hi_bound) / 2;
        if (fnc(lo_bound) * fnc(mid) <= 0)
        {
            hi_bound = mid;
        }
        else if (fnc(mid) * fnc(hi_bound) <= 0)
        {
            lo_bound = mid;
        }
        iter++;
    }
    cout << setprecision(15) << mid;
    return 0;
}