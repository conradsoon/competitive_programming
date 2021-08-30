#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, P;
    cin >> N >> P;
    vector<int> studentsListening;
    studentsListening.reserve(N);
    int be = 0, sum = 0;
    int input;
    while(cin >> input){
        studentsListening.push_back(input-P);
    }
    for(int k = 0; k < N; k++){
        sum = max(studentsListening[k], sum + studentsListening[k]);
        be = max(be, sum);
    }
    cout << be;
    return 0;
}