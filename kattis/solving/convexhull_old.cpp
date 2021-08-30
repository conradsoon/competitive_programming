#include <iostream>
#include <string>
#include <vector>
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

struct point
{
    ld x;
    ld y;
    ld z;
};

point min_pt;
ld dist(const point &a, const point &b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
ld z(const point &a, const point &b)
{
    return a.x * b.y - a.y * b.x;
}
bool operator<(const point &lhs, const point &rhs)
{
    ld dist_lhs = dist(min_pt, lhs);
    ld dist_rhs = dist(min_pt, rhs);
    ld angle_lhs = lhs.z / dist_lhs;
    ld angle_rhs = rhs.z / dist_rhs;
    if (angle_lhs == angle_rhs)
    {
        return dist_lhs < dist_rhs;
    }
    else
    {
        return angle_lhs < angle_rhs;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin >> n && n != 0)
    {
        vector<point> pts(n);
        int min_index = 0;
        for (int i = 0; i < n; i++)
        {
            ld x, y;
            cin >> x >> y;
            pts[i] = {x, y, 0};
        }
        for (int i = 0; i < n; i++)
        {
            if (pts[i].y < pts[min_index].y)
            {
                min_index = i;
            }
            else if (pts[i].y == pts[min_index].y)
            {
                if (pts[i].x < pts[min_index].x)
                {
                    min_index = i;
                }
            }
        }
        min_pt = pts[min_index];
        for (int i = 0; i < n; i++)
        {
            pts[i].z = z(min_pt, pts[i]);
        }
        sort(pts.begin(), pts.end());
    }
    return 0;
}