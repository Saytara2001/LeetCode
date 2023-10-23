class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)
            return false;
        bool isPowerOfTwo = (n & (n - 1)) == 0;;
        return (isPowerOfTwo & (n % 3 == 1));
    }
};