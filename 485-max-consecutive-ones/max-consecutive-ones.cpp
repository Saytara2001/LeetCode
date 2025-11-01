class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int prev = 0, maxOnes = 0, cnt = 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) maxOnes = max(maxOnes, 1);
            if(prev == 1 and prev == nums[i]) {
                maxOnes = max(maxOnes, ++cnt);
            } else {
                cnt = 1;
            }
            prev = nums[i];
        }
        return maxOnes;
    }
};