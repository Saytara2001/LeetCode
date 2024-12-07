class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int dpMax = 1, dpMin = 1;
        int maxRes = INT_MIN;
        
        for(int i = 0; i < size(nums); i++) {
            if(nums[i] == 0) {
                dpMax = dpMin = 1;
                maxRes = max(maxRes, 0);
                continue;
            }
            
            int prevMax = dpMax;
            dpMax = max({dpMax * nums[i], dpMin * nums[i], nums[i]});
            dpMin = min({prevMax * nums[i], dpMin * nums[i], nums[i]});
            
            maxRes = max(maxRes, dpMax);
        }
        
        return maxRes;
    }
};