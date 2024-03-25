class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = size(nums);
        vector<int> res;
        //use visited on the same array but with negative value
        //to make sure of visited before we put negative at index
        for(int i = 0; i < n; i++) {
            int pos = abs(nums[i]) - 1;
            if(nums[pos] < 0) 
                res.push_back(abs(nums[i]));
            nums[pos] = -1 * abs(nums[pos]);
        }
        return res;
    }
};