class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        const int mod = 1e9 + 7;
        int max_val = *max_element(nums.begin(), nums.end());
        vector<vector<int>> idx(max_val + 1);
        for (int i = 0; i < n; i++) {
            idx[nums[i]].push_back(i);
        }
        int z = idx[0].size();
        long long ans =
            (1LL * z * (z - 1) * (z - 2) / 6) % mod; // combination of zeros

        for (int val = 1; val <= max_val / 2; val++) {
            for(auto j: idx[val]) {
                int need = val * 2;
                auto before = upper_bound(begin(idx[need]), end(idx[need]), j) - begin(idx[need]);
                int after = idx[need].size() - before;
                ans = (ans + 1LL * before * after % mod) % mod;
            }
        }
        return ans;
    }
};