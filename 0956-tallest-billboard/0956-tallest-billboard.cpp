class Solution {
public:
    int dp[20][10001];
    int solve(int idx, int diff, vector<int> &rods)
    {
        if(idx == rods.size()) {
            if(diff == 0) {
                return 0;
            }
            return -1e5;
        }
        int &ret = dp[idx][diff + 5000];
        
        if(~ret)
            return ret;

        int ans1 = solve(idx+1, diff, rods);  

        int ans2 = rods[idx] + solve(idx+1, diff + rods[idx], rods); 

        int ans3 = rods[idx] + solve(idx+1, diff - rods[idx], rods);  

        return ret = max(ans1, max(ans2, ans3));
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0,0,rods) / 2; 
        return ans;
    }
};