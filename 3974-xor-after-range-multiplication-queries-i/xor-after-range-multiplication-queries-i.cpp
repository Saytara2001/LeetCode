class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int mod = 1e9 + 7;
        for(int i = 0; i < queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1], k = queries[i][2], v = queries[i][3];
            int idx = l;
            while(idx <= r) {
                nums[idx] = (1LL * nums[idx] * v) % mod;
                idx += k;
            }
        }
        int ans = 0;
        for(auto x: nums) {
            ans ^= x;
        }
        return ans;
    }
};