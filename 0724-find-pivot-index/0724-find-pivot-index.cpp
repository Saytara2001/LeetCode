class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1; i < n; i++)
            nums[i] += nums[i-1];
        for(int i = 0; i < n; i++) {
            int pre = i == 0 ? 0 : nums[i-1];
            int post = i == n-1? 0 :nums[n-1] - nums[i];
            if(pre == post) return i;
        }
        return -1;
    }
};