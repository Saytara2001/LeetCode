class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        for(int i = 0; i < size(nums); i += 3) {
            if(nums[i + 2] - nums[i] > k) {
                //no answer
                return {};
            }
            res.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return res;
    }
};