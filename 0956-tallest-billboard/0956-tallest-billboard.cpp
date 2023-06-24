class Solution {
public:
    int dp[20][10001];
    int solve(int i, int diff, vector<int> &rods)
    {
        if(i == rods.size()) {
            if(diff == 0) {
                return 0;
            }
            return -1e5;
        }
        
        int &ret = dp[i][diff + 5000];
        if(~ret)
            return ret;

        int ans1 = solve(i+1, diff, rods);  

        int ans2 = solve(i+1, diff + rods[i], rods) + rods[i]; 

        int ans3 = solve(i+1, diff - rods[i], rods);  

        return ret = max(ans1, max(ans2, ans3));
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp, -1, sizeof(dp));
        return solve(0,0,rods);
    }
};