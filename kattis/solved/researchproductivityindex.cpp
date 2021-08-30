#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int prob;
    vector<int> p;
    while(cin >> prob){
        p.push_back(prob);
    }
    sort(p.begin(),p.end(),greater<int>());
    int iterations = 10000;
    double max = -1;
    for(int i = 0; i < n; i++){
        double ri = 0;
        int s = i + 1;
        for(int j = 0; j < iterations; j++){
            int a = 0;
            for(int k = 0; k < s; k++){
                int ran = rand() % 100;
                if(ran<p[k]){
                    a++;
                }
            }
            ri += pow((double)a,(double)a/s);
        }
        double expri = ri/iterations;
        if(expri>max){
            max=expri;
        }
    }
    cout << setprecision(10) << max;
    return 0;
}