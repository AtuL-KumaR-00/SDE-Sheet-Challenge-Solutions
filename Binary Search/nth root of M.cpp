long double multiply(double number, double n){
    long double ans=1.0;
    for(int i=1; i<=n; i++)
    {
        ans=ans*number;
    }
    return ans;
}

double findNthRootOfM(int n, long long m) {
	// Write your code here.
    double error=1e-7;
    long double lo=0;
    long double hi=m;
    while(abs(hi-lo)>(long double)error){
        long double mid=lo + (hi-mid)/2.0;
        if(multiply(mid,n)== (long double)m){
            return mid;
        }else if(multiply(mid,n)>(long double)m){
            hi=mid;
        }
        else{
            lo=mid;
        }
    }
    return hi;
}
