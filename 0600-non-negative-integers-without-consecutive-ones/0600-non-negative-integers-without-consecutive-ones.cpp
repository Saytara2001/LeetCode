class Solution {
public:
    int findIntegers(int n) {
        vector<int> dp(32);
        for(int i = 0; i < 32; i++) {
            if(i <= 1) {
                dp[i] = i + 1;
                continue;
            }
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        int i = 30, sum = 0, prev_bit = 0;
        while(i >= 0) {
            if((1 << i) & n) {
                sum += dp[i];
            }
            
            if(prev_bit and ((1 << i) & n))
                return sum;
            
            prev_bit = (1 << i) & n;
            
            --i;
        }
        
        return sum + 1; //1 for n itself it's valid
    }
};