#include <bits/stdc++.h>
#include <unordered_map>

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
string strfy(int a, int b)
{
    return to_string(a) + "," + to_string(b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t;
    cin >> n >> t;
    unordered_map<string, int> cache;
    while (t--)
    {
        int k;
        cin >> k;
        int l = 1, r = n, m;
        vector<pair<int, int>> hist;
        while (l != r)
        {
            int a;
            m = (l + r) / 2;
            hist.push_back({l, m});
            if (cache.find(strfy(l, m)) == cache.end())
            {
                cout << "? " << l << " " << m << "\n";
                cout.flush();
                cin >> a;
                cache[strfy(l, m)] = a;
            }
            a = cache[strfy(l, m)];
            a = (m - l + 1) - a;
            if (k > a)
            {
                l = m + 1;
                k -= a;
            }
            else
            {
                r = m;
            }
        }
        for (auto p : hist)
        {
            if (l >= p.first && l <= p.second)
            {
                cache[strfy(p.first, p.second)]++;
            }
        }
        cout << "! " << l << "\n";
        cout.flush();
    }
    return 0;
}