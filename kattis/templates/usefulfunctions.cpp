//useful functions
int msb(unsigned long n){
    int b = 0;
    while(n!=0){
        n >>= 1;
        b++;
    }
    return b;
}

int modexp(unsigned long a, unsigned long b, unsigned long n){
    unsigned long result = 1;
    vector<unsigned long> ap;
    ap.push_back(a%n);
    for(int i=0; b!=0; i++){
        if(i>0){
            ap[i]=(ap[i-1]*ap[i-1])%n;
        }
        if(b&1){
            result=((result)*(ap[i]))%n;
        }
        b>>=1;
    }
    return result;
}

int lsb(int s){
    return (s & (-s));
}