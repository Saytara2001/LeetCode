class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = size(nums);
        int l = 0, r = 0, uni = 0, res = 0;
        vector<int> freq(2e4 + 1);
        int cnt = 0;
        while(r < n) {
            //move r and take one element
            uni += (freq[nums[r]] == 0);
            freq[nums[r++]]++;
            //if have more than k diffrerent element move left
            if(uni > k) {
                freq[nums[l++]]--;
                uni--;
                cnt = 0;
            }
            if(uni == k) {
                //while still valid count the answer
                while(l < n and freq[nums[l]] > 1) {
                    --freq[nums[l++]];
                    cnt++;
                }
                res += cnt + 1;
            }
        }
        return res;
    }
};