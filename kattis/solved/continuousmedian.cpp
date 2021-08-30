#include <iostream>
#include <string>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

template <class T>
using ordered_set = tree<
    T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;

struct number
{
    int val;
    int index; //disgusting hack to turn ordered_set into a multiset
};

bool operator<(const number &lhs, const number &rhs)
{
    if (lhs.val == rhs.val)
    {
        return lhs.index < rhs.index;
    }
    else
    {
        return lhs.val < rhs.val;
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
        int n;
        cin >> n;
        ll sum = 0;
        ordered_set<number> pbds;
        for (int i = 1; i <= n; i++)
        {
            int num;
            cin >> num;
            pbds.insert({num,i});
            if (i % 2 == 1)
            {
                sum += (*pbds.find_by_order((i+1)/2-1)).val;
            }
            else if (i % 2 == 0)
            {
                sum += ((*pbds.find_by_order((i/2)-1)).val + (*pbds.find_by_order(i/2)).val)/2;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}