#include <bits/stdc++.h>
using namespace std;
int d, s, itr=100;
long double pre = 0.00000000000005;
long double af(long double a){
    //cout << "a = "<< a <<" f(a)=" << a+s-a*cosh(d/(2*a)) << endl;
    return a+s-a*cosh(d/(2*a));
}

long double binary(long double s, long double e){
    long double m = (s+e)/2;
    if(af(m+pre)*af(m-pre)<0){
    //itr--;
    //if(itr==0){
        return m;
    }
    else if(af(s)*af(m)<0){
        return binary(s,m);
    }
    else if (af(m)*af(e)<0){
        return binary(m,e);
    }
    else{
        return -1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> d >> s;
    long double a = binary(pre,125001);
    cout << setprecision(16) << 2*a*sinh(d/(2*a));
}