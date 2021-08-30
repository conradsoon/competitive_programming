#include <bits/stdc++.h>
using namespace std;
/*
map<int,set<int>> cache;
cache.insert(make_pair(1,set<int>(1)));
set<int> sequence(int n){
    int max_elements = -1;
    int max_index;
    for(int i = 1; i < n; i++){
        if(n%i == 0){
            if(cache.count(i)==0){
                cache.insert(make_pair(i,sequence(i)));
            }
            if(sequence(i)+1>max_elements){
                max_elements==
            }
        }
    }
]
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    set<int> seq;
    seq.insert(n);
    while(n!=1){
        int i = 2;
        while(n % i != 0){
            i++;
        }
        n/=i;
        seq.insert(n);
    }
    int size = seq.size();
    cout << size << "\n";
    int i = 0;
    for(int no : seq){
        cout << no;
        if(i != size-1){
            cout << " ";
        }
        i++;
    }
    return 0;
}