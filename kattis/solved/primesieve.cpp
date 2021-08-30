#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n;
    int q;
    bool pr;
    int no;
    long i,j;
    cin >> n >> q;
    vector<long> primes={2};
    unordered_set<long> prlist={2};
    if(n>=2){
        for(i=2; i*i<=n; i++){
            pr = true;
            for(const auto& p: primes){
                if(i%p==0){
                    pr=false;
                    break;
                }
            }
            if(pr==true){
                primes.push_back(i);
                prlist.insert(i);
            }
        }
        while(i<=n){
            pr = true;
            for(const auto& p: primes){
                if(i%p==0){
                    pr=false;
                    break;
                }
            }
            if(pr==true){
                primes.push_back(i);
                prlist.insert(i);
            }
            i++;
        }
        cout << prlist.size() << "\n";
    }
    else{
        cout << "0" << "\n";
    }

    while(q--){
        cin >> no;
        cout << (prlist.count(no) > 0 ? "1" : "0") << "\n";
    }
    return 0;
}

/*
        for(long i=2; i*i<=n; i++){
            pr = true;
            for(const auto& p: primes){
                if(i%p==0){
                    pr=false;
                    break;
                }
            }
            if(pr==true){
                primes.insert(i);
            }
        }
*/