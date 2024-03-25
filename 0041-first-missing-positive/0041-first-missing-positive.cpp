class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = size(nums);
        for(int i = 0; i < n; i++) {
            //not interested with negative numbers && numbers greather than n
            if(nums[i] < 0 or nums[i] > n) 
                nums[i] = 0;
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0 or nums[i] == -(n + 1)) continue;
            int pos = abs(nums[i]) - 1;
            nums[pos] = abs(nums[pos]) == 0 ? -(n + 1) : -abs(nums[pos]);
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] >= 0)
                return i + 1;
        }
        return n + 1;
    }
};