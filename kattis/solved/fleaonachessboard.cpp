#include <iostream>
#include <string>
#include <vector>

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

//template ends
bool is_on_white(int s, int x, int y)
{
    //deals with edge case, literally
    if (y % s == 0 || x % s == 0)
    {
        return false;
    }
    //notice that sum of squares from origin is odd when square is black, and even when square is white.
    return (((x / s) + (y / s)) % 2 == 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s, x, y, dx, dy;
    while (cin >> s >> x >> y >> dx >> dy && s != 0)
    {
        bool is_possible = false;
        int no_jumps = 0;
        //1005 is an arbitrary max constant chosen.
        for(; no_jumps < 1005; ++no_jumps){
            if(is_on_white(s,x,y)){
                is_possible = true;
                break;
            }
            else{
                x += dx;
                y += dy;
            }
        }
        if (is_possible)
        {
            cout << "After " << no_jumps << " jumps the flea lands at (" << x << ", " << y << ").\n";
        }
        else
        {
            cout << "The flea cannot escape from black squares.\n";
        }
    }
    return 0;
}