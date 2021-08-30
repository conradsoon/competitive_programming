#include <iostream>
#include <string>
#include <vector>
#include <random>
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

#define MAX_ITER 400
#define PREC 0.0000001

struct point
{
    ll x;
    ll y;
};

//collinear points give determinant of 0 because displacement vectors are scalar multiples
bool is_collinear(const point &p1, const point &p2, const point &p3)
{
    ll dx1 = p3.x - p1.x;
    ll dx2 = p3.x - p2.x;
    ll dy1 = p3.y - p1.y;
    ll dy2 = p3.y - p2.y;
    return (dx1 * dy2 - dy1 * dx2 == 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    ll p;
    cin >> n >> p;
    ll min = n * p / 100;
    if (((n * p) % 100 != 0))
    {
        min++;
    }
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<ll> distrib(0, n - 1);
    bool is_possible = false;
    vector<point> pts(n);
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        pts[i] = {x, y};
    }
    if (n <= 2)
    {
        cout << "possible";
        return 0;
    }
    for (ll i = 0; i < MAX_ITER; i++)
    {
        ll p1 = distrib(gen);
        ll p2 = distrib(gen);
        if (p1 == p2)
        {
            continue;
        }
        ll count = 0;
        for (ll j = 0; j < n; j++)
        {
            if (is_collinear(pts[p1], pts[p2], pts[j]))
            {
                count++;
            }
        }
        if (count >= min)
        {
            is_possible = true;
            break;
        }
    }
    cout << (is_possible ? "possible" : "impossible");
    return 0;
}