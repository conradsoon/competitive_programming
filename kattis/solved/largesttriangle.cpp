#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
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
    ll x;
    ll y;
};

bool operator<(const point &lhs, const point &rhs)
{
    if (lhs.x == rhs.x)
    {
        return lhs.y < rhs.y;
    }
    else
    {
        return lhs.x < rhs.x;
    }
}
bool ccw(const point &a, const point &lh, const point &c)
{
    point ab = {a.x - lh.x, a.y - lh.y};
    point bc = {lh.x - c.x, lh.y - c.y};
    return ab.x * bc.y - ab.y * bc.x <= 0;
}
ld det(const point &a, const point &b)
{
    return (ld)a.x * (ld)b.y - (ld)a.y * (ld)b.x;
}
ld area(const point &a, const point &b, const point &c) //shoelace
{
    ld area = 0;
    area += det(a, b);
    area += det(b, c);
    area += det(c, a);
    area /= 2;
    return abs(area);
}
int next(int index, int no)
{
    return (index + 1) % no;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    set<point> pts;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        pts.insert({x, y});
    }
    vector<point> lh; //lower hull, using andrew's algorithm
    for (auto it = pts.rbegin(); it != pts.rend(); it++)
    {
        lh.push_back(*it);
        while (lh.size() >= 3 && ccw(*(lh.end() - 1), *(lh.end() - 2), *(lh.end() - 3)))
        {
            lh.erase(lh.end() - 2);
        }
    }
    vector<point> uh; //upper hull, using andrew's algorithm
    for (auto it = pts.begin(); it != pts.end(); it++)
    {
        uh.push_back(*it);
        while (uh.size() >= 3 && ccw(*(uh.end() - 1), *(uh.end() - 2), *(uh.end() - 3)))
        {
            uh.erase(uh.end() - 2);
        }
    }
    vector<point> hull;
    for (int i = 1; i < uh.size() - 1; i++)
    {
        hull.push_back(uh[i]);
    }
    for (int i = 0; i < lh.size(); i++)
    {
        hull.push_back(lh[i]);
    }
    if (hull.size() < 3) //no convex hull how to find largest inscribed triangle?
    {
        cout << "0";
    }
    //https://arxiv.org/abs/1705.11035
    //quadratic time algorithm found here
    else
    {
        int a = 0;
        int b = 1;
        int c = 2;
        int no = hull.size();
        ld m = area(hull[a], hull[b], hull[c]);
        while (true)
        {
            while (c != a)
            {
                while (area(hull[a], hull[b], hull[next(c, no)]) >= area(hull[a], hull[b], hull[c]))
                {
                    if(c==a){
                        break;
                    }
                    c = next(c, no);
                }
                if (area(hull[a], hull[b], hull[c]) >= m)
                {
                    m = area(hull[a], hull[b], hull[c]);
                }
                b = next(b, no);
            }
            a = next(a, no);
            if (a == 0)
            {
                break;
            }
            b = next(a, no);
            c = next(b, no);
        }
        cout << setprecision(15);
        cout << m;

        //o(n^3) //brute force, will time out
        /**
        ld m = 0;
        for (int i = 0; i < hull.size(); i++)
        {
            for (int j = 1; j < hull.size(); j++)
            {
                for (int k = 2; j < hull.size(); j++)
                {
                    m = max(m, area(hull[i],hull[j],hull[k]));
                }
            }
        }
        cout << m;
        **/
    }
    return 0;
}