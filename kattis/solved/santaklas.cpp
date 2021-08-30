#include <bits/stdc++.h>
using namespace std;
# define M_PI           3.14159265358979323846  /* pi */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h, v;
    cin >> h >> v;
    if(v <= 180){
        cout << "safe\n";
    }
    else{
        double hyp = -h/sin(M_PI*v/180);
        cout << floor(hyp);
    }
    return 0;
}