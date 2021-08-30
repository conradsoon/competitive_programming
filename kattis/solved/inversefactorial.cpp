#include <bits/stdc++.h>
#include <string>

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
    string inverse;
    cin >> inverse;
    if(inverse=="720"){
        cout << 6;
    }
    else if(inverse=="120"){
        cout << 5;
    }
    else if(inverse=="24"){
        cout << 4;
    }
    else if(inverse=="6"){
        cout << 3;
    }
    else if(inverse=="2"){
        cout << 2;
    }
    else if(inverse=="1"){
        cout << 1;
    }
    else{
        int i=7;
        while(ceil(fd(i))<inverse.length()){
            i++;
        }
        cout << i;
    }
    return 0;
}