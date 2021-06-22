#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef long int l;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

//template ends
const int ITR = 1001;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, useless1, useless2;
    cin >> n >> useless1 >> useless2;
    vector<ld> probs(n + 1);
    vector<int> depth(n + 1);
    depth[1] = 0;
    probs[1] = 1;
    vvi children(n + 1);
    int a, b;
    for (int i = 1; i < n; i++) //tree has n-1 edges
    {
        cin >> a >> b;
        children[a].push_back(b);
    }
    //dfs to find depth
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        for (auto c : children[q.front()])
        {
            depth[c] = depth[q.front()] + 1;
            q.push(c);
        }
        q.pop();
    }
    for (int k = 0; k < ITR; k++)
    {
        vector<ld> temp(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (children[i].size() == 0)
            {
                temp[1] += probs[i];
            }
            else
            {

                ld prob = probs[i] / children[i].size();
                for (auto c : children[i])
                {
                    temp[c] += prob;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            probs[i] = temp[i];
        }
    }
    //setprecision
    return 0;
}