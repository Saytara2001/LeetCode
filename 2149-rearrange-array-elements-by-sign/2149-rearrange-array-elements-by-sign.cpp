class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = size(nums), posIdx = 0, posNeg = 1;
        vector<int> res(n);
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                res[posIdx] = nums[i];
                posIdx += 2;
            }else {
                res[posNeg] = nums[i];
                posNeg += 2;
            }
        }
        return res;
    }
};