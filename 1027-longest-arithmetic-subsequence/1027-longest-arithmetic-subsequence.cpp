class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1);
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            
            dp[i] = unordered_map<int, int>();
            
            for (int j = 0; j < i; ++j) {
                int cnt = 1;
                
                int diff = nums[i] - nums[j];

                if(dp[j].count(diff))
                    cnt = dp[j][diff];

                dp[i][diff] = cnt + 1;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};