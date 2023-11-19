class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int segment = 0, n = size(nums);
        int ans = 0;
        for(int i = 0; i < n ; i++) {
            int cur = i;
            while(cur < n and nums[cur] == nums[i]) {
                cur++;
            }
            ans += (cur - i) * segment;
            i = cur - 1;
            segment++;
        }
        return ans;
    }
};