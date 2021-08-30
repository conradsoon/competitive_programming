#include <iostream>
#include <string>
#include <vector>
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
int toMins(string tfh)
{
    int h = stoi(tfh.substr(0, 2));
    int m = stoi(tfh.substr(3, 2));
    return h * 60 + m;
}
vector<ld> roots(ld angle)
{
    ld c = angle;
    vector<ld> rts;
    while (c < 8640)
    {
        if (c / 5.5 >= 0)
        {
            rts.push_back(c / 5.5);
        }
        c += 360;
    }
    return rts;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ld> zero = roots(0);
    vector<ld> ninety = roots(90);
    vector<ld> n_ninety = roots(-90);
    vector<ld> one_eighty = roots(180);
    while (n--)
    {
        string s, e;

        int angle;
        cin >> s >> e >> angle;
    
        int start = toMins(s);
        int end = toMins(e);
        int sum = 0;
        if (angle == 0)
        {
            sum += upper_bound(zero.begin(),zero.end(),end)-lower_bound(zero.begin(),zero.end(), start);
        }
        else if (angle == 90)
        {
            sum += upper_bound(ninety.begin(),ninety.end(),end)-lower_bound(ninety.begin(),ninety.end(), start);
            sum += upper_bound(n_ninety.begin(),n_ninety.end(),end)-lower_bound(n_ninety.begin(),n_ninety.end(), start);
            
        }
        else if (angle == 180)
        {
            sum += upper_bound(one_eighty.begin(),one_eighty.end(),end)-lower_bound(one_eighty.begin(),one_eighty.end(), start);
        }
        cout << sum << "\n";
    }
    return 0;
}