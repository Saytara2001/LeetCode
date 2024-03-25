class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = size(nums);
        //use visited on the same array but with negative value
        //to make sure of visited before we put negative at index
        for(int i = 0; i < n; i++) {
            int pos = abs(nums[i]) - 1;
            if(nums[pos] < 0) 
                return abs(nums[i]);
            nums[pos] = -1 * abs(nums[pos]);
        }
        return -1;
    }
};