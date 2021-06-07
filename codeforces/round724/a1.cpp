
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
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    bool flag = true;
    set<int> present;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < 0)
        {
            flag = false;
        }
        present.insert(a[i]);
    }
    if (flag)
    {
        set<int> added;
        stack<int> to_find;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (j == i)
                {
                    continue;
                }
                int diff = abs(a[i] - a[j]);
                if (present.find(diff) == present.end())
                {
                    if (added.find(diff) == added.end())
                    {
                        added.insert(diff);
                        to_find.push(diff);
                    }
                }
            }
        }
        while (!to_find.empty())
        {
            int new_one = to_find.top();
            to_find.pop();
            a.push_back(new_one);
            present.insert(new_one);
            if (a.size() > 300)
            {
                flag = false;
                break;
            }
            for (int i = 0; i < a.size() - 1; i++)
            {
                int diff = abs(a[i] - new_one);
                if (present.find(diff) == present.end())
                {
                    to_find.push(diff);
                }
            }
        }
        if (!flag)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            cout << a.size() << "\n";
            for (int i = 0; i < a.size(); i++)
            {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}