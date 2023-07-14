class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int, int> dp;
        int mx = 0;
        
        for(auto cur: arr) {
            int pre = dp.find(cur - difference) != end(dp) ? dp[cur - difference] : 0;
            dp[cur] = pre + 1;
            mx = max(mx, dp[cur]);
        }
        
        return mx;
    }
};