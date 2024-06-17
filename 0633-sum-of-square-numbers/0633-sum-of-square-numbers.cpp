class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int a = 0; a <= 1e5; a++) {
            long long cal = c - 1LL * a * a;
            if(cal < 0) break;
            long long b = sqrtl(cal);
            if(b * b == cal)
                return true;
        }
        return false;
    }
};