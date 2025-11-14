class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> freq(51);
        int l = 0;
        vector<int> res(n - k + 1);
        for(int r = 0; r < n; r++) {
            if(nums[r] < 0) ++freq[abs(nums[r])];
            if(r >= k - 1) {
                // get the ans
                int have = 0;
                for(int f = 50; f >= 1; f--) {
                    have += freq[f];
                    if(have >= x) {
                        res[l] = -f;
                        break;
                    }
                }
                if(nums[l] < 0) --freq[abs(nums[l])];
                ++l;
            }
        }
        return res;
    }
};