#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

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

#define INF numeric_limits<l>::max() //check to see if can fit inside 32 bit integer variables
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    l n;
    while (cin >> n)
    {
        vector<long> seq(n);
        vector<long> d(n + 1, INF);
        vector<long> d_index(n + 1, -1);
        d[0] = -INF;
        vector<long> p(n + 1, -1);
        for (l i = 0; i < n; i++)
        {
            cin >> seq[i];
        }
        for (l i = 0; i < n; i++)
        {
            l j = upper_bound(d.begin(), d.end(), seq[i]) - d.begin();
            if (d[j - 1] < seq[i] && seq[i] < d[j])
            {
                d[j] = seq[i];
                d_index[j] = i;
                p[j] = d_index[j - 1];
            }
        }
        l ans = 0;
        for (l i = 0; i <= n; i++)
        {
            if (d[i] < INF)
                ans = i;
        }
        cout << ans << "\n";
        vector<long> ans_ind;
        ans_ind.push_back(d_index[ans]);
        for (l i = ans; i > 1; i--)
        {
            ans_ind.push_back(p[i]);
        }
        sort(ans_ind.begin(), ans_ind.end());
        for(l i = 0; i<ans_ind.size(); i++){
            cout << ans_ind[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}