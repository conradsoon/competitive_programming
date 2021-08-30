#include <iostream>
#include <string>
#include <vector>
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
typedef long double ld;
//template ends

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c, p, x, l;
    cin >> c >> p >> x >> l;
    x--;
    l--;
    vvi graph(c);
    vi conns(c, 0);
    vi no_left(c, 0);
    vector<bool> left(c, false);
    for (int i = 0; i < p; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        conns[a]++;
        conns[b]++;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    stack<int> check;
    left[l] = true;
    for (int i : graph[l])
    {
        no_left[i]++;
        check.push(i);
    }
    while (!check.empty())
    {
        int ctry = check.top();
        check.pop();
        if (left[ctry])
        {
            continue;
        }
        int no_ctry_left = no_left[ctry];
        int no_conn_ctry = conns[ctry];
        if (no_ctry_left >= (no_conn_ctry % 2 + no_conn_ctry) / 2)
        {
            left[ctry] = true;
            for (int i : graph[ctry])
            {
                no_left[i]++;
                check.push(i);
            }
        }
    }
    cout << (left[x] ? "leave" : "stay");
    return 0;
}