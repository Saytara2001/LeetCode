class Solution {
public:
    int dp[105][105];
    vector<int> v;
    int rec(int i, int lst) {

        if (i == v.size())
            return 0;

        int &ret = dp[i][lst];
        if (~ret)
            return ret;

        int leave = rec(i + 1, lst);
        int take = 0;

        if (i - lst > 1 or lst == v.size())
            take = rec(i + 1, i) + v[i];

        return ret = max(take, leave);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        for(auto vv:nums) {
            v.push_back(vv);
        }
        return rec(0, nums.size());
    }
};