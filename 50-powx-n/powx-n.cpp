class Solution {
public:
    double myPow(double x, int n) {
     if(n == 0)
        return 1.0;
    long long N = n; 
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
     double t = pow(x,N/2);
     if(N % 2 == 0)
        return t*t;
     else
         return x*t*t;

    }
};