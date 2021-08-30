#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    int req;
    int max_reqs = 1;
    vector<int> reqs;

    cin >> n >> k;
    while(cin >> req){
        reqs.push_back(req);
    }
    for(int i=0; i<n; i++){
        int j=i-1;
        int reqm = 1;
        while(j>=0 && reqs[i]-reqs[j]<1000){
            reqm++;
            j--;
        }
        if(reqm>max_reqs){
            max_reqs=reqm;
        }
    }
    
    cout << ((max_reqs%k) ? ((max_reqs-max_reqs%k)/k+1) : (max_reqs/k)) << "\n";
    return 0;
}