class Solution {
public:
    vector<int> v;
    int dp[2501][2501];
    int rec(int i, int prev) {
        if (i == v.size())
            return 0;

        int &ret = dp[i][prev];
        if (~ret)
            return ret;

        int leave = 0, take = INT_MIN;
        leave = rec(i + 1, prev);
        
        if(i == prev) {
            take = rec(i + 1, i) + 1;
            leave = rec(i + 1, i + 1);
        }else if (v[i] > v[prev]) {
            take = rec(i + 1, i) + 1;
        }
        return ret = max(take, leave);
    }
    int lengthOfLIS(vector<int>& nums) {
        for(auto vv : nums) {
            v.push_back(vv);
        }
        memset(dp, -1, sizeof(dp));
        
        return rec(0, 0);
    }
};