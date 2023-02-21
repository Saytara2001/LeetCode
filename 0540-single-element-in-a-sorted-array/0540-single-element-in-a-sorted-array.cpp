class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for(auto vv:nums)
            res ^= vv;
        return res;
    }
};