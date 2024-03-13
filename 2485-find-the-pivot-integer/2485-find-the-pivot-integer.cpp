class Solution {
public:
    int pivotInteger(int n) {
        int sum  = n * (n + 1) / 2;
        int have = 0;
        for(int i = 1; i <= n; i++) {
            have += i;
            if(sum == have)
                return i;
            sum -= i;
        }
        return -1;
    }
};