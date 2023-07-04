class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int ans = 0;
        for(int i = 0 ;i < size(nums); i++) {
            int j = i, cnt = 0;
            while(j < size(nums) and nums[i] == nums[j]) {
                j++;
                cnt++;
            }
            if(cnt == 1) {
                ans = nums[i];
                break;
            }
            i = j - 1;
        }
        return ans;
    }
};