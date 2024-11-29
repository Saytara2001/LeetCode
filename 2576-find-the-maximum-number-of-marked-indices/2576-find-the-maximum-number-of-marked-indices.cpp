class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = size(nums);
        int r = n / 2, cnt = 0;
        for(int i = 0; i < n / 2 and r < n; r++) {
            if(nums[i] * 2 <= nums[r]) {
                cnt += 2;
                i++;
            }
        }
        
        return cnt;
    }
};