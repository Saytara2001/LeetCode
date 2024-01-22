class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = size(nums);
        int all = n * (n + 1) / 2;
        int sum = 0;
        int repeated;
        sort(begin(nums), end(nums));
        for(int i = 0; i < n; i++) {
            if(i > 0 and nums[i] == nums[i - 1])
                repeated = nums[i];
            sum += nums[i];
        }
        int missed = all - sum + repeated;
        return {repeated, missed};
    }
};