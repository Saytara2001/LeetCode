class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = size(nums), lst = nums[0] - k - 1;
        int dis = 0;
        for(int i = 0; i < n; i++) {
            int gen = max(lst + 1, nums[i] - k);
            if(gen >= nums[i] - k and gen <= nums[i] + k) {
                ++dis;
                lst = gen;
            }
        }
        return dis;
    }
};