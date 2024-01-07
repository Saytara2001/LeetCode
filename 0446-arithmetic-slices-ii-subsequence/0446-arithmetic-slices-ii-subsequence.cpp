class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = size(nums);
        long long ans = 0;
        map<pair<int, long long>, long long> dp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                long long diff = 1LL * nums[i] - nums[j];
                dp[{i, diff}] += dp[{j, diff}] + 1;
                ans += dp[{j, diff}];
            }
        }
        return ans;
    }
};