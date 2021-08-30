#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin >> n && n != 0){
        int a, b;
        vector<int> x, y;
        long double area=0;
        int i = n;
        while(i--){
            cin >> a >> b;
            x.push_back(a);
            y.push_back(b);
        }
        x.push_back(x[0]);
        y.push_back(y[0]);
        for(int i = 0; i < n; i++){
            area += x[i] * y[i+1];
            area -= y[i] * x[i+1];
        }
        area/=2;
        cout << (area>0?"CCW ":"CW ") << fixed << setprecision(1) <<abs(area) << "\n";
    }
    return 0;
}