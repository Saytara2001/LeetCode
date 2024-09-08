class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        int lst = nums[0];
        int n = size(nums);
        for(int i = 0; i < n - 1; i++) {
            int cur = i + 1;
            while(cur + 1 < n and nums[i] > nums[cur]) {
                cur++;
            }
            ans += 1LL * (cur - i) * nums[i];
            lst = nums[cur];
            i = cur - 1;
        }
        
        return ans;
    }
};