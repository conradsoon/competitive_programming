#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned int n;
    unsigned int q;
    bool pr;
    unsigned int no;
    cin >> n >> q;
    unordered_set<unsigned int> primes={2};
    unordered_set<unsigned int> composites={1};
    if(n>=2){
        for(unsigned int i=2; i*i<=n; i++){
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
        for(const auto& p: primes){
            for(unsigned int i=2; i*p <=n; i++){
                composites.insert(i*p);
            }
        }
        cout << n-composites.size() << "\n";
    }
    else{
        cout << "0" << "\n";
    }

    while(q--){
        cin >> no;
        cout << (composites.count(no) > 0 ? "0" : "1") << "\n";
    }
    return 0;
}

/*
        for(unsigned int i=2; i*i<=n; i++){
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