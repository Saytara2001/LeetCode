class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n < 4 or nums[0] >= nums[1])
            return false;
        
        bool inc = 0, dec = 0, inc2 = 0;
        for (int i = 1; i < n; i++) {
            if(nums[i] > nums[i - 1] and !dec and !inc2) {
                inc = true;
            } else if(nums[i] < nums[i - 1] and inc and !inc2) {
                dec = 1;
            } else if(nums[i] > nums[i - 1] and inc and dec) {
                inc2 = true;
            } else {
                return false;
            }
        }
        return inc and dec and inc2;
    }
};