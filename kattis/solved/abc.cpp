#include <bits/stdc++.h>
#include <string>

using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int numbers[3]={a,b,c};
    sort(numbers, numbers+3);
    string cs;
    cin >> cs;
    for(int i=0;i<3;i++){
        char m = cs[i];
        if(m == 'A'){
            printf("%d", numbers[0]);
        }
        else if(m == 'B'){
            printf("%d", numbers[1]);
        }
        else if(m == 'C'){
            printf("%d", numbers[2]);
        }
        if(i<2){
            printf(" ");
        }
    }
}