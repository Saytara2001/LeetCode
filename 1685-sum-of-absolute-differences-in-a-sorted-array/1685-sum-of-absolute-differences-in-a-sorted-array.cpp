class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int suffix = 0, n = size(nums);
        for(int i = 0; i < n; i++) {
            suffix += nums[i];
        }
        int prefix = 0;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            suffix -= nums[i];
            int calc = (1LL * nums[i] * i - prefix) + (suffix - 1LL * nums[i] * (n - i - 1));
            prefix += nums[i];
            res.push_back(calc);
        }
        return res;
    }
};