class Solution {
public:
    double BinPow(double a, long b) {
        double res = 1.0;
        while (b > 0) {
            if (b & 1) {
                res = res * a;
            }
            a = a * a;
            b >>= 1;
        }
        return res;
    } 
    double myPow(double x, int n) {
        double ans = BinPow(x, abs(long(n)));
        if(n < 0)
            ans = 1.0 / ans;
        return ans;
    }
};