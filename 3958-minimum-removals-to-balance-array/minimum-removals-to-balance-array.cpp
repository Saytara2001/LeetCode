class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int minOp = n;
        for (int i = 0; i < n; i++) {
            auto idx = upper_bound(begin(nums), end(nums), 1LL * nums[i] * k) - begin(nums);
            int bad = n - (idx - i);
            minOp = min(minOp, bad);
        }
        return minOp;
    }
};