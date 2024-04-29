class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xr = 0;
        for(auto it: nums) {
            xr ^= it;
        }
        int cnt = 0;
        for(int i = 0; i < 30; i++) {
            int a = k >> i;
            int b = xr >> i;
            if((a & 1) != (b & 1)) cnt++;
        }
        return cnt;
    }
};