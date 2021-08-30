#include <iostream>
#include <string>
#include <vector>
#include <numeric>
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
    int x;
    int y;
};
bool is_compatible(point a, point b)
{
    if (a.x == b.x)
    {
        return false;
    }
    if (a.y == b.y)
    {
        return false;
    }
    if (abs(a.x - b.x) == abs(a.y - b.y))
    {
        return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    vector<point> pts;
    bool valid = true;
    for (int i = 0; i < 8; i++)
    {
        cin >> input;
        for (int j = 0; j < 8; j++)
        {
            if (input[j] == '*')
            {
                pts.push_back({i, j});
            }
        }
    }
    for (int i = 0; i < 8 && valid; i++)
    {
        for (int j = i + 1; j < 8; j++)
        {
            if(!is_compatible(pts[i],pts[j])){
                valid = false;
                break;
            }
        }
    }
    cout << (valid ? "valid" : "invalid");
    return 0;
}