class Solution {
public:
    int dp[1000][1001];
    int rec(int i, int lst, vector<int>& nums) {

        if(i == size(nums))
            return 0;
        
        int &ret = dp[i][lst + 1];
        if(~ret)
            return ret;

        int take = 0, leave = 0;

        if(lst == -1 or nums[i] % nums[lst] == 0) 
            take = rec(i + 1, i, nums) + 1;

        leave = rec(i + 1, lst, nums);

        return ret = max(take, leave);
    }
    void build(int i, int lst, vector<int>& nums, vector<int>& ans) {

        if(i == size(nums))
            return;

        int ret = dp[i][lst + 1];
        
        int take = rec(i + 1, i, nums) + 1;
        int leave = rec(i + 1, lst, nums);

        if((lst == -1 or nums[i] % nums[lst] == 0) and ret == take) {
            ans.push_back(nums[i]);
            build(i + 1, i, nums, ans);
            return;
        }

        build(i + 1, lst, nums, ans);

    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums), end(nums));
        memset(dp, -1, sizeof dp);
        int res = rec(0, -1, nums);
        vector<int> ans;
        build(0, -1, nums, ans);
        return ans;
    }
};