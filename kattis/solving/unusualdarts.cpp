#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
struct dart
{
    ld x;
    ld y;
};
ld area(const vector<dart> &d, const vi &p)
{
}

ld grad(const dart &a, const dart &b)
{
    return (a.y - b.y) / (a.x - b.x);
}
void check_intersect(const dart &d1, const dart &d2, const dart &d3, const dart &d4, bool &do_not_intersect)
{
    ld g1 = grad(d1, d2);
    ld g2 = grad(d3, d4);
    if (g1 == g2)
    {
        do_not_intersect = true;
    }
    else
    {
    }
}
bool is_simple(const vector<dart> &d, const vi &p)
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = i + 1; j < 7; j++)
        {
            bool do_not_intersect;
            check_intersect(d[i], d[(i + 1) % 7], d[j], d[(j + 1) % 7], do_not_intersect);
        }
    }
}

void solve()
{
    vector<dart> d(7);
    for (int i = 0; i < 7; i++)
    {
        cin >> d.x >> d.y;
    }
    ld prob;
    cin >> prob;
    ld a = pow(prob, (ld)1 / (ld)3);
    vi p = {0, 1, 2, 3, 4, 5, 6};
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}