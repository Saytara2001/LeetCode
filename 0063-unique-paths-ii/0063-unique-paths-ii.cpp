class Solution {
public:
    int n, m;
    int dp[101][101];
    int rec(int i, int j,vector<vector<int>>& obstacleGrid) {
        
        if(i >= n or j >= m or obstacleGrid[i][j])
            return 0;
        
        if(i == n-1 and j == m-1)
            return 1;
        
        int &ret = dp[i][j];
        if(~ret)
            return ret;
        
        ret = 0;
        ret += rec(i + 1, j, obstacleGrid);
        ret += rec(i, j + 1, obstacleGrid);
        
        return ret;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof dp);
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        return rec(0 ,0, obstacleGrid);
    }
};