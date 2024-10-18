class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        
        for(auto it: nums)
            maxOR |= it;
        
        int n = size(nums);
        int count = 0;
        for(int mask = 0; mask < (1 << n); mask++) {
            int curOR = 0;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    curOR |= nums[i];
                }
            }
            count += (maxOR == curOR);
        }
        
        return count;
    }
};