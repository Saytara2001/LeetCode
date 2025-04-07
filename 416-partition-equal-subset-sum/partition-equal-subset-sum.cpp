class Solution {
public:
    int dp[200][20001];
    int tot = 0;
    int rec(int i, int sum, vector<int>& nums) {

        if(i == size(nums)) 
            return tot - 2 * sum == 0;

        int &ret = dp[i][sum];
        if(~ret)
            return ret;

        ret = 0;
        ret |= rec(i + 1, sum, nums);
        ret |= rec(i + 1, sum + nums[i], nums);

        return ret;
    }
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        tot = accumulate(begin(nums), end(nums), 0);
        cout << tot << endl;
        return rec(0, 0, nums);
    }
};