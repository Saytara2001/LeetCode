class Solution {
public:
    int bs(int left, int right, vector<int>& nums, int target) {
        int l = left, r = right;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) {
                return mid;
            }else if(nums[mid] > target) {
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        //find the pivot index
        int n = size(nums);
        int l = 0, r = n - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[n - 1]) {
                l = mid + 1;
            }else {
                r = mid;
            }
        }
        //search for target
        int answer = bs(0, l - 1, nums, target);
        if(answer != -1)
            return answer;
        answer = bs(l, n - 1, nums, target);
        return answer;
    }
};