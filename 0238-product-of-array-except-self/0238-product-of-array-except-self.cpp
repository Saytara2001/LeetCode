class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //like prefix and suffix
        int n = size(nums);
        vector<int> ans(n, 1); 
        int p = 1;
        for(int i = 0; i  < n; i++) {
            ans[i] = p;
            p *= nums[i];
        }
        p = 1;
        for(int i = n - 1; i >= 0; i--) {
            ans[i] *= p;
            p *= nums[i];
        }
        return ans;
    }
};