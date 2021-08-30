#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
struct ivl
{
    ld l;
    ld r;
    int i;
};

bool operator<(const ivl &lhs, const ivl &rhs)
{
    if (lhs.l == rhs.r)
    {
        return lhs.r > rhs.r;
    }
    else
    {
        return lhs.l < rhs.l;
    }
}
const ld prec = 0.00000001;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ld a, b;
    while (cin >> a >> b)
    {
        int n;
        cin >> n;
        vector<ivl> itvls(n);
        for (int i = 0; i < n; i++)
        {
            itvls[i].i = i;
            cin >> itvls[i].l >> itvls[i].r;
        }
        sort(itvls.begin(), itvls.end());
        bool is_possible = true;
        vector<int> min_cover;
        ld target = a;
        ld best = a;
        vector<ivl>::iterator best_it;
        for (auto it = itvls.begin(); it != itvls.end(); it++)
        {
            if ((*it).l <= target)
            {
                best_it = it;
                best = max(best, (*it).r);
            }
            else
            {
                if (best < target)
                {
                    is_possible = false;
                    break;
                }
                min_cover.push_back((*best_it).i);
                target = best;
            }
        }
        if (target < b)
        {
            is_possible = false;
        }
        if (is_possible)
        {
            cout << min_cover.size() << "\n";
            for(auto i : min_cover){
                cout << i << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "impossible\n";
        }
    }
    return 0;
}