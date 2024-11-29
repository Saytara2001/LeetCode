class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = size(nums);
        
        int l = 0, r = n - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if((mid - 1 < 0 or nums[mid] > nums[mid - 1]) and (mid + 1 >= n or nums[mid] > nums[mid + 1]))
                return mid;
            if(mid + 1 < n and nums[mid] > nums[mid + 1]) {
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        return r;
    }
};