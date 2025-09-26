class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = size(nums);
        int triplets = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n ; j++) {
                int sum = nums[i] + nums[j];
                int idx = lower_bound(begin(nums) + j + 1, end(nums), sum) - begin(nums);
                int res = idx - j - 1;
                triplets += res;
            }
        }
        return triplets;
    }
};