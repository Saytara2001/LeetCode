class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = size(nums);
        vector<int> pref(n + 1);
        int cnt = 0, op = 0;
        for(int i = 0; i < n; i++) {
            if(i > 0) pref[i] ^= pref[i - 1];
            nums[i] ^= pref[i];
            if(nums[i] == 0 and i + k <= n) {
                op++;
                pref[i] ^= 1;
                nums[i] = 1;
                pref[i + k] ^= 1;
            }
            cnt += nums[i];
        }
        return cnt == n ? op : -1;
    }
};