class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        const int mod = 1e9 + 7;
        unordered_map<int, int> freq, pre;
        for(auto x: nums) {
            ++freq[x];
        }
        long long ans = 0;
        for(auto x: nums) {
            int need = 2 * x;
            int after = freq[need] - pre[need] - (x == need);
            ans = (ans + 1LL * pre[need] * after % mod) % mod;
            ++pre[x];
        }
        return ans;
    }
};