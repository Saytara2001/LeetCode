class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        int n = nums.size(), cnt = 0;;
        for(int i = 0; i < n - 1; i++) {
            sum -= 2 * nums[i];
            cnt += (sum % 2 == 0);
        }
        return cnt;
    }
};