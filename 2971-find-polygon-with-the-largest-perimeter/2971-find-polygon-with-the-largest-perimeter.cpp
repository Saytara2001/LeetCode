class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(begin(nums), end(nums));
        long long mx = -1;
        int n = size(nums);
        long long prefixSum = 0;
        for(int i = 0; i < n; i++) {
            if(i > 1 and nums[i] < prefixSum) {
                mx = prefixSum + nums[i];
            }
            prefixSum += nums[i];
        }
        return mx;
    }
};