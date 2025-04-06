class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = size(nums);
        sort(begin(nums), end(nums));
        vector<int> dp(n, 1), par(n, -1);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[j] % nums[i] == 0 and dp[j] < dp[i] + 1) {
                    dp[j] = dp[i] + 1;
                    par[j] = i;
                }
            }
        }
        int mx = max_element(begin(dp), end(dp)) - begin(dp);
        vector<int> ans;
        while(mx != -1) {
            ans.push_back(nums[mx]);
            mx = par[mx];
        }
        reverse(begin(nums), end(nums));
        return ans;
    }
};