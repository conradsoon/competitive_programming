#include <iostream>
#include <string>
#include <vector>
#include <set>

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

//Referenced from Michael Pfeifer, https://github.com/mpfeifer1/Kattis/blob/master/gcpc.cpp
template <class T>
using ordered_set = tree<
    T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;

struct quest
{
    int e = 0;
    int g = 0;
    //disgusting hack to turn ordered set into multiset
    int index = 0;
    quest(int e, int g, int index)
    {
        this->e = e;
        this->g = g;
        this->index = index;
    }
};

bool operator<(const quest &lhs, const quest &rhs)
{
    if (lhs.e == rhs.e)
    {
        if (lhs.g == rhs.g)
        {
            return lhs.index > rhs.index;
        }
        else
        {
            return lhs.g < rhs.g;
        }
    }
    else
    {
        return lhs.e < rhs.e;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ordered_set<quest> quests;
    int n;
    cin >> n;
    while (n--)
    {
        string comm;
        cin >> comm;
        if (comm == "add")
        {
            int energy, gold;
            cin >> energy >> gold;
            quests.insert(quest(energy, gold, n));
        }
        else if (comm == "query")
        {
            int amount;
            ll sum = 0;
            cin >> amount;
            while (amount >= 0)
            {
                quest query = quest(amount + 1, 0, 0);
                int order = quests.order_of_key(query);
                if (order == 0)
                {
                    break;
                }
                else
                {
                    quest current_quest = *quests.find_by_order(order - 1);
                    sum += current_quest.g;
                    amount -= current_quest.e;
                    quests.erase(current_quest);
                }
            }
            cout << sum << "\n";
        }
    }
    return 0;
}