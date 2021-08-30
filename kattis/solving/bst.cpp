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

//Ordered Set from policy based data structures
//implemented as a binary search tree so i'm just abusing it
template <class T>
using ordered_set = tree<
    T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ordered_set<int> bst;
    int n;
    ll c = 0;
    cin >> n;
    while (n--)
    {
        int inp;
        cin >> inp;
        int order = bst.order_of_key(inp);
        bst.insert(inp);
        while (order)
        {
            c++;
            order >>= 1;
        }
        cout << c << "\n";
    }
    return 0;
}