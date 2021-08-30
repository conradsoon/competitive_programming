#include <bits/stdc++.h>
#include <vector>
#include <limits>

using namespace std;
vector<int> shts;
int n;

double length(int size){
    return pow(2, 0.25 -0.5*size);
}

double make_paper(int amt, int size){
    int idx = size - 2;
    int addtl_req = amt - shts[idx];
    //if ask for too small, just break;
    if(size > n){
        return -std::numeric_limits<double>::infinity();
    }
    if(addtl_req > 0){
        return length(size+1)*(addtl_req) + make_paper(addtl_req*2,size+1);
    }
    else{
        shts[idx] -= amt;
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    int input;

    while(cin >> input){
        shts.push_back(input);
    }
    double tape_used = length(2) + make_paper(2, 2);
    cout.precision(15);
    if(tape_used < 0){
        cout << "impossible\n";
    }
    else{
        cout << tape_used << "\n";
    }
    return 0;
}