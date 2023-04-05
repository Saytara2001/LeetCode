class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long  mx = 0;
        long long pre = 0;
        for(int i = 0; i < size(nums); i++) {
            pre += nums[i];
            mx = max(mx, (pre + i) / (i + 1)); //ceil
        } 
        return mx;
    }
};