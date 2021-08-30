#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <stack>
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
struct tile
{
    int r;
    int c;
};
tile operator+(const tile &a, const tile &b)
{
    return {a.r + b.r, a.c + b.c};
}
bool valid_tile(int n, int m, const tile& t)
{
    return t.r >= 0 && t.r <= n + 1 && t.c >= 0 && t.c <= m + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> grid(n + 2, vector<bool>(m + 2));
    for (int i = 1; i < n + 1; i++)
    {
        string line;
        cin >> line;
        for (int j = 1; j < m + 1; j++)
        {
            grid[i][j] = (line[j - 1] == '1' ? 1 : 0);
        }
    }
    vector<vector<bool>> sea_tiles(n + 2, vector<bool>(m + 2));
    stack<tile> bfs;
    bfs.push({0,0});
    vector<tile> directions;
    directions.push_back({0, 1});
    directions.push_back({1, 0});
    directions.push_back({0, -1});
    directions.push_back({-1, 0});
    while (!bfs.empty()) //finds all sea tiles
    {
        tile t = bfs.top();
        bfs.pop();
        for (auto dir : directions)
        {
            tile test_t = dir + t;
            if (valid_tile(n, m, test_t) && sea_tiles[test_t.r][test_t.c] == false && grid[test_t.r][test_t.c] == false)
            {
                sea_tiles[test_t.r][test_t.c] = true;
                bfs.push(test_t);
            }
        }
    }
    ll length = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (grid[i][j] == 1)
            {
                length += sea_tiles[i - 1][j] + sea_tiles[i][j - 1] + sea_tiles[i + 1][j] + sea_tiles[i][j + 1];
            }
        }
    }
    cout << length;
    return 0;
}