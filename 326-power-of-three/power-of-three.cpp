class Solution {
public:
    bool isPowerOfThree(int n) {

        if(n <= 0) 
            return false;

        long long x = 3486784401; // 3 ^ 20
        
        return x % n == 0;
    }
};