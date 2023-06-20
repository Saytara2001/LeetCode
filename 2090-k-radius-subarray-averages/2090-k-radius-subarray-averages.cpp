class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int len = 2 * k + 1, n = nums.size();
        vector<int> ans(n, -1);
        
        long long sum = 0;
        int l = 0, r = 0, idx = k;
        while(r < n) {
            if(r - l < len) {
                sum += nums[r++];
            }else {
                ans[idx++] = sum / len;
                sum -= nums[l++];
                sum += nums[r++];
            }
        }
        if(r - l == len)
            ans[idx++] = sum / len;
        return ans;
    }
};