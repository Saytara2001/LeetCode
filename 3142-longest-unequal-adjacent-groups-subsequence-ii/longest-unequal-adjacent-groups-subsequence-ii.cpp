class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = size(words);
        vector<int> dp(n, 1), par(n, -1);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                
                if(size(words[i]) != size(words[j]) or groups[i] == groups[j])
                    continue;
                
                int diff = 0;
                for(int k = 0; k < size(words[i]); k++) {
                    diff += words[i][k] != words[j][k];
                }
                
                if(diff != 1)
                    continue;
                
                if(dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    par[i] = j;
                }
            }
        }
        
        int mxIdx = (max_element(dp.begin(), dp.end()) - dp.begin());
        vector<string> ans;
        
        while (mxIdx != -1) {
            ans.push_back(words[mxIdx]);
            mxIdx = par[mxIdx];
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};