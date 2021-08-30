#include <bits/stdc++.h>
using namespace std;

vector<long double> cache={0,0};
int maxfd=1;

long double fd(int i){
    if(i==0||i==1){
        return 1;
    }
    else{
        long double d = 0;
        if(maxfd < i){
            for(int j=maxfd+1; j<=i; j++){
                cache.push_back(cache[j-1]+log10(j));
            }
            maxfd=i;
        }
        return cache[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int f;
    while(cin >> f){
        cout << (unsigned long long)ceil(fd(f)) << "\n";
    }
    return 0;
}