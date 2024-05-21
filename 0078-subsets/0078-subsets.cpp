class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for(int msk = 0; msk < (1 << n); msk++) {
            vector<int> v;
            for(int i = 0; i < n; i++) {
                if(msk & (1 << i)) {
                    v.push_back(nums[i]);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};