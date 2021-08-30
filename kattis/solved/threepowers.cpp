#include <bits/stdc++.h>
using namespace std;

vector<unsigned long long> exp3={1};
unsigned long long maxexp=0;

unsigned long long lsb(unsigned long long s){
    unsigned long long mask = 1;
    while((mask&s)==0){
        mask<<=1;
    }
    return mask;
}

unsigned long long pow3(unsigned long long lsb){
    unsigned long long lsbi = log2(lsb);
    for(maxexp;maxexp<lsbi;maxexp++){
        exp3.push_back(exp3[maxexp]*3);
    }
    return exp3[lsbi];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long n;
    while(cin >> n, n!=0){
        n--;
        cout << "{ ";
        while(n!=0){
            unsigned long long lsbno=lsb(n);
            cout << fixed << pow3(lsbno);
            n-=lsbno;
            if(n!=0){
                cout << ", ";
            }
        }
        cout << " }\n";
    }
}