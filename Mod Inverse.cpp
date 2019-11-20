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

	   //Update y , x;
	   y = x - q*y;
	   x = t;
	}

	///make x positive
	if(x<0) x+= m0;
	
	return x;
}