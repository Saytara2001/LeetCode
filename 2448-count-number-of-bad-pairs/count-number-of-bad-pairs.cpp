class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        int n = size(nums);
        long long res = 1LL * n * (n - 1) / 2;

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            res -= mp[nums[i] - (i + 1)]++;
        }

        return res;
    }
};