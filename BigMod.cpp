/// a^b % M = ???

int bigMod(int a, int b , int M){
        if(b==0) return 1%M;
        int x = bigMod(a, b/2 , M);
        x = (x*x) % M; /// x = ((x%M) * (x%M)) % M --- possible optimization
        if(b%2) x = (x*a) % M; /// x = ((x%M) * (a%M)) % M;
        return x;
}


/// complexity O(logN)