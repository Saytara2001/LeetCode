class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2);
        int xr = 0;
        for(auto it: nums) {
            xr ^= it;
        }
        int j = 0;
        while((xr & 1) == 0) {
            j++;
            xr >>= 1;
        }
        for(auto it: nums) {
            if(it & (1 << j)) {
                res[0] ^= it;
            }else {
                res[1] ^= it;
            }
        }
        return res;
    }
};