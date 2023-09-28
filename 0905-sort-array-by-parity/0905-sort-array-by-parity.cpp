class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        int l = 0, r = n - 1;
        for(auto& it: nums) {
            it & 1 ? v[r--] = it : v[l++] = it;
        }
        return v;
    }
};