class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) 
            return false;

        if(n == 1)
            return true;

        bool ok = true;
        ok &= (__builtin_ctz(n) % 2 == 0); // check trailing zeros
        ok &= (n % 2 == 0); // check parity
        ok &= ((n & (n - 1)) == 0);  // check power of 2s
        return ok;
    }
};