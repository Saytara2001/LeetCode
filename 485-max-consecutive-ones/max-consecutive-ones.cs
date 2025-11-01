public class Solution {
    public int FindMaxConsecutiveOnes(int[] nums) {
        int maxOnes = 0;
        int n = nums.Length;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 1) continue;
            int cur = i, cnt = 0;
            while(cur < n && nums[i] == nums[cur]) {
                ++cur;
                ++cnt;
            }
            i = cur;
            maxOnes = Math.Max(maxOnes, cnt);
        }
        return maxOnes;
    }
}