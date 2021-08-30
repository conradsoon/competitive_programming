#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <tuple>

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
template <class T>
using ordered_set = tree<
    T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;

//Referenced from Michael Pfeifer, https://github.com/mpfeifer1/Kattis/blob/master/gcpc.cpp
struct score
{
    int team = 0;
    int solved = 0;
    int penalty = 0;
};

bool operator<(const score &lhs, const score &rhs)
{
    if (lhs.solved == rhs.solved)
    {
        if (lhs.penalty == rhs.penalty)
        {
            return lhs.team < rhs.team;
        }
        return lhs.penalty < rhs.penalty;
    }
    return lhs.solved > rhs.solved;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    ordered_set<score> leaderboard;
    cin >> n >> m;
    map<int, score> team_to_score;
    for (int i = 0; i < n; i++)
    {
        score team;
        team.team = i;
        leaderboard.insert(team);
    }
    while (m--)
    {
        int t, p;
        cin >> t >> p;
        if(team_to_score.find(t) == team_to_score.end()){
            team_to_score[t].team = t;
        }
        leaderboard.erase(team_to_score[t]);
        team_to_score[t].solved++;
        team_to_score[t].penalty += p;
        leaderboard.insert(team_to_score[t]);
        cout << leaderboard.order_of_key(team_to_score[1])+1 << "\n";
    }
    return 0;
}