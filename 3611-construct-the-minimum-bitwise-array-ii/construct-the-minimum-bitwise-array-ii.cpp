class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(auto& x: nums) {
            int pow = 1, res = -1;
            while((x & pow) != 0) {
                res = x - pow;
                pow <<= 1;
            }
            x = res;
        }
        return nums;
    }
};