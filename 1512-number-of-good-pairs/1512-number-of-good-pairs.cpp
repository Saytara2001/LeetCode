class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int freq[101] = {0};
        for(auto it: nums)
            freq[it]++;
        int ans = 0;
        for(int i = 1; i <= 100; i++) {
            ans += freq[i] * (freq[i] - 1) / 2;
        }
        return ans;
    }
};