class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int l = 0, r = 2;
        int cnt =  0;
        while(r < size(nums)) {
            int a = nums[l] + nums[r];
            int b = nums[l + 1];
            cnt += (a * 2 == b);
            ++l, ++r;
        }

        return cnt;
    }
};