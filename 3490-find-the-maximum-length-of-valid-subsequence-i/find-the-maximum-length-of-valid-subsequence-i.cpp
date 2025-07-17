class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = size(nums);
        vector<vector<int>> v(2);
        int even = 0, odd = 0, alt = 1, lst = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] & 1) ++odd;
            if(!(nums[i] & 1)) ++even;

            if(lst == -1) 
                lst = nums[i];
            else if(lst % 2 != nums[i] % 2) {
                lst = nums[i];
                ++alt;
            }
        }
        return max({even, odd, alt});
    }
};