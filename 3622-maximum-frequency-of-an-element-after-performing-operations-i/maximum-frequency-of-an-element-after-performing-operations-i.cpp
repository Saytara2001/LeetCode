class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        int n = nums.size();
        int max_value = *max_element(begin(nums), end(nums));

        vector<int> freq(max_value + 1);
        for(auto v: nums) {
            ++freq[v];
        }

        for(int i = 1; i <= max_value; i++)
            freq[i] += freq[i - 1];

        int maxFreq = 0;
        for(int i = 0; i <= max_value; i++) {
            int left = max(0, i - k);
            int right = min(max_value, i + k);
            int tot = freq[right] - (left ? freq[left - 1] : 0);
            int curFreq = freq[i] - (i ? freq[i - 1] : 0);
            maxFreq = max(maxFreq, curFreq + min(numOperations, tot - curFreq));
        }
        return maxFreq;
    }
};