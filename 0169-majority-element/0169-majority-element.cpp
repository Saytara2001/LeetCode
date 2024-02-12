class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        sort(begin(nums), end(nums));
        int n = size(nums);
        
        for(int i = 0; i < n; i++) {
            int cur = i;
            while(cur < n and nums[i] == nums[cur]) cur++;
            if(cur - i > n / 2)
                return nums[i];
            i = cur - 1;
        }
        return 0;
    }
};