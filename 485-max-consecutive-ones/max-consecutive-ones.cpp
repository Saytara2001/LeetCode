class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] != 1) continue;
            int cur = i;
            while(cur < n and nums[i] == nums[cur]) {
                ++cur;
            }
            maxOnes = max(maxOnes, cur - i);
            i = cur - 1;
        }
        return maxOnes;
    }
};