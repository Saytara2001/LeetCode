class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> v(size(nums));
        int l = 0, r = size(nums) - 1;
        for(auto it: nums) {
            it & 1 ? v[r--] = it : v[l++] = it;
        }
        return v;
    }
};