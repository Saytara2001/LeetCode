class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = size(nums);
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                mp[nums[i] * nums[j]]++;
            }
        }
        int count = 0;
        for(auto [a, b]: mp) {
            count += b * (b - 1) / 2 * 8;
        }
        return count;
    }
};