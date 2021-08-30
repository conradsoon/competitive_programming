#include <iostream>
#include <string>
#include <vector>
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
void iter(ll &x)
{
    if (x % 2 == 0)
    {
        x = x / 2;
    }
    else
    {
        x = 3 * x + 1;
    }
}
int main()
{
    //repeating a lot of calculations, consider memoing it later
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b;
    while (cin >> a >> b && a != 0)
    {
        ll a_iter_count = 0;
        ll b_iter_count = 0;
        ll start_a = a;
        ll start_b = b;
        unordered_map<ll, ll> a_visited;
        unordered_map<ll, ll> b_visited;
        while (true)
        {
            if (a_visited.count(a) != 1)
            {
                a_visited[a] = a_iter_count;
            }
            if (b_visited.count(b) != 1)
            {
                b_visited[b] = b_iter_count;
            }
            if (a_visited.count(b) == 1)
            {
                printf("%lld needs %lld steps, %lld needs %lld steps, they meet at %lld\n", start_a, a_visited[b], start_b, b_iter_count, b);
                break;
            }
            else if (b_visited.count(a) == 1)
            {
                printf("%lld needs %lld steps, %lld needs %lld steps, they meet at %lld\n", start_a, a_iter_count, start_b, b_visited[a], a);
                break;
            }
            if (a != 1)
            {
                iter(a);
                a_iter_count++;
            }
            if (b != 1)
            {
                iter(b);
                b_iter_count++;
            }
        }
    }
    return 0;
}