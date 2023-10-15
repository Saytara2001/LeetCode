class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //like prefix and suffix
        int n = size(nums);
        vector<int> ans(n, 1); 
        int p = 1;
        for(int i = 0; i + 1 < n; i++) {
            p *= nums[i];
            ans[i + 1] = p;
        }
        p = 1;
        for(int i = n - 1; i > 0; i--) {
            p *= nums[i];
            ans[i - 1] *= p;
        }
        return ans;
    }
};