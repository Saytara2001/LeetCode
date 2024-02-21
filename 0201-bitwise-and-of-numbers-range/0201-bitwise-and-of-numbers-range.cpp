class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        //to make sure bit will be one in all numbers 
        //must to be between two consecutive powers of 2's
        //so if right i can subtract from him power of 2's then this bit will be 0
        vector<bool> bit(33);
        for(int i = 0; i <= 31; i++) {
            bit[i] = (1LL << i) & right;
        }
        int j = 0;
        for(int i = left; (1LL << j) + left <= right; i++) {
            bit[j] = 0;
            j++;
        }
        long long ans = 0;
        for(int i = 0; i <= 32; i++) {
            if(bit[i]) {
                ans += (1LL << i);
            }
        }
        ans &= (left & right);
        return ans;
    }
};