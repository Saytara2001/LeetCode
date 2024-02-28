class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = size(nums);
        int l = 0 , r = n - 1;
        int operations = 0;
        while(l < r) {
            int sum = nums[l] + nums[r];
            if(sum == k) {
                l++, r--;
                operations++;
                continue;
            }
            sum > k ? r-- : l++;
        }
        return operations;
    }
};