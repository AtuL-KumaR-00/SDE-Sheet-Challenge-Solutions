#include <bits/stdc++.h>  

int modularExponentiation(int xx, int n, int m) {

// Write your code here.

    long long int result=1;

    long long x=xx;

    for(int i = n; i!=0; i/=2)

    {

     if (i%2)  

           result=(result*x%m)%m;

     x=(x%m*x%m)%m;

    }

    return int(result%m);

}