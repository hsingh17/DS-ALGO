class Solution {
public:
    double myPow(double x, int n) {
        // Method 1: Obvious Brute Force Method is to keep multiplying x by itself n times. (TLE)
        // Method 2: Divide & Conquer.
        //           Base case: n == 0 return 1
        //           Check if n is even. If even split into 1 case with x and n/2. Return ret*ret
        //           If n is odd split into 1 cases with x and n-1. Return ret*x
        
        if (n == 0)
            return 1;
        
        if (n % 2) {
            double ret = myPow(x, abs(n)-1);
            return (n > 0) ? ret*x : 1/(ret*x);
        } else {
            double ret = myPow(x, abs(n)/2);
            return (n > 0) ? ret*ret : 1/(ret*ret);
        }
    }
};
