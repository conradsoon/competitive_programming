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
struct sprinkler
{
    ld l, r;
};
bool operator<(const sprinkler &lhs, const sprinkler &rhs)
{
    if (lhs.l == rhs.l)
    {
        return lhs.r > rhs.r;
    }
    return lhs.l < rhs.l;
}
ld precision = 0.0000001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    ld l, w;
    while (cin >> n >> l >> w)
    {
        vector<sprinkler> s;
        ld pos, rad;
        for (int i = 0; i < n; i++)
        {
            cin >> pos >> rad;
            if (rad - w / 2)
            {
                ld width = sqrt(pow(rad, 2) - pow(w / 2, 2));
                if (width > precision)
                {
                    s.push_back({pos - width, pos + width});
                }
            }
        }
        sort(s.begin(), s.end());
        ld right = 0;
        ld next = 0;
        int amt = 1;
        bool possible = true;
        //with reference from https://github.com/mpfeifer1/Kattis/blob/master/grass.cpp
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i].l <= right)
            {
                next = max(s[i].r, next);
            }
            else
            {
                if (abs(next - right) < precision)
                {
                    possible = false;
                    break;
                }
                right = next;
                i--;
                amt++;
            }
        }
        if (next < l)
        {
            possible = false;
        }
        cout << (possible ? amt : -1) << "\n";
        //if r is less than l, then it failed
    }
    return 0;
}