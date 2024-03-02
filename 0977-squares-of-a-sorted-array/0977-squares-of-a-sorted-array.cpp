class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = size(nums);
        int pos = n, neg = n - 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] >= 0) {
                pos = i;
                neg = i - 1;
                break;
            }
        }
        vector<int> res;
        while(neg >= 0 or pos < n) {
            if(neg >= 0 and pos < n) {
                if(nums[neg] * nums[neg] <= nums[pos] * nums[pos])
                    res.push_back(nums[neg] * nums[neg--]);
                else 
                    res.push_back(nums[pos] * nums[pos++]);
            }else {
                if(neg >= 0)
                    res.push_back(nums[neg] * nums[neg--]);
                else 
                    res.push_back(nums[pos] * nums[pos++]);
            }
        }
        return res;
    }
};