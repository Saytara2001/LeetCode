class Solution {
public:
    int subarraysWithKDistinct(vector<int> &nums, int k) {
        int n = nums.size();

        auto atMost_K_Different = [&](int K)-> int {
            int l = 0, distinct = 0, sub = 0;
            vector<int> freq(n + 1);
            for (int r = 0; r < n; ++r) {
                distinct += (++freq[nums[r]] == 1);
                while (distinct > K) {
                    distinct -= !(--freq[nums[l++]]);
                }
                sub += r - l + 1;
            }
            return sub;
        };

        return atMost_K_Different(k) - atMost_K_Different(k - 1);
    }
};