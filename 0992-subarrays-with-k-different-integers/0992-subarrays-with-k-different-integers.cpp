class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = size(nums);
        int l = 0, r = 0, uni = 0, res = 0;
        vector<int> freq(2e4 + 1);
        while(l < n or r < n) {
            while(r < n and (freq[nums[r]] or uni < k)) {
                uni += (freq[nums[r]] == 0);
                freq[nums[r++]]++;
                if(uni == k) res++;
            }
            if(l < n) {
                if(--freq[nums[l++]] == 0) uni--;
                if(uni == k) res++;
                //decrease r again when it's always valid
                while(l < r and freq[nums[r - 1]] > 1) {
                    freq[nums[--r]]--;
                }
            }
        }
        return res;
    }
};