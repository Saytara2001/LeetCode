class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)
            return false;
        bool isPowerOfTwo = (n & (n - 1)) == 0;
        bool hasEvenZeros = __builtin_ctz(n) % 2 == 0;
        return (isPowerOfTwo & hasEvenZeros);
    }
};