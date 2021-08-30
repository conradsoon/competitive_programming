#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
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
struct student
{
    ll long_no;
    ll short_no;
};
bool operator<(const student &lhs, const student &rhs)
{
    return lhs.long_no < rhs.long_no;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<student> stdt_list(n);
    for (ll i = 0; i < n; i++)
    {
        ll long_no;
        cin >> long_no;
        stdt_list[i] = {long_no, i};
    }
    sort(stdt_list.begin(), stdt_list.end());
    ll inversions = 0;
    for (ll i = 0; i < n; i++)
    {
        inversions += abs(i - stdt_list[i].short_no);
    }
    cout << inversions / 2;
    return 0;
}