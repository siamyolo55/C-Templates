int modInverse(int a, int m){
	int m0 = m;
	int y = 0 , x = 1;

	if(m == 1) return 0;

	while(a>1){
	   /// q = quotient
	   int q = a/m;
	   int t = m;

	   /// m = remainder now, process same as Euclid's algo
	   m = a%m , a = t;
	   t = y;

	   ///Update y , x;
	   y = x - q*y;
	   x = t;
	}

	///make x positive
	if(x<0) x+= m0;

	return x;
}

int findMinX(int num[] , int rem[], int k){	/// x % num[0] = rem[0]
						///....................
						/// x % num[k-1] = rem[k-1]
    ///compute product of all numbers
    int prod = 1;
    for(int i=0;i<k;i++) prod *= num[i];

    ///initialize result
    int result = 1;

    for(int i=0;i<k;i++){
        int pp = prod/num[i];
        result += rem[i] * modInverse(pp , num[i]) * pp;
    }

    return result % prod;
}
