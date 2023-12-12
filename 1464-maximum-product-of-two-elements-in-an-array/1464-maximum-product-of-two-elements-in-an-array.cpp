class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx1 = 0, mx2 = size(nums) - 1;
        for(int i = 0; i < size(nums) ;i++) {
            if(nums[i] > nums[mx1] and i != mx2) {
                mx1 = i;
            }
        }
        for(int i = 0; i < size(nums) ;i++) {
            if(nums[i] > nums[mx2] and i != mx1) {
                mx2 = i;
            }
        }
        return --nums[mx1] * --nums[mx2];
    }
};