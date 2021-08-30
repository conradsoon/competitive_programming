#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <set>
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin >> n && n != 0)
    {
        set<point> pts;
        for (int i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            pts.insert({x, y});
        }
        if (pts.size() >= 3)
        {
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
            cout << (lh.size() - 1) + (uh.size() - 1) << "\n";
            for (int i = lh.size() - 2; i >= 0; i--)
            {
                cout << lh[i].x << " " << lh[i].y << "\n";
            }
            for (int i = uh.size() - 2; i >= 0; i--)
            {
                cout << uh[i].x << " " << uh[i].y << "\n";
            }
        }
        else
        {
            cout << pts.size() << "\n";
            for (auto it = pts.rbegin(); it != pts.rend(); it++)
            {
                cout << (*it).x << " " << (*it).y << "\n";
            }
        }
    }
    return 0;
}