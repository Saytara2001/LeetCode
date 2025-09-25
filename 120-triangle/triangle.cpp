class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp { 0 };
        int n = triangle.size();
        for(int i = 0; i < n; i++) {
            vector<int> cur;
            for(int j = 0; j < triangle[i].size(); j++) {
                int minSum = 1e9;
                if(j - 1 >= 0) 
                    minSum = min(minSum, dp[j - 1] + triangle[i][j]);
                if(j < dp.size()) 
                    minSum = min(minSum, dp[j] + triangle[i][j]);
                cur.push_back(minSum);
            }
            dp = cur;
        }
        return *min_element(begin(dp), end(dp));
    }
};