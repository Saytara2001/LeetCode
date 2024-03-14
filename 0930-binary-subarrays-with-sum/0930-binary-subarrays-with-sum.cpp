class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        map<int, int> mp{{0, 1}};
        int ans = 0;
        
        for(int i = 1; i < size(nums); i++) 
            nums[i] += nums[i - 1];
        
        for(int i = 0;i < size(nums); i++) {
            ans += mp[nums[i] - goal];
            mp[nums[i]]++;
        }
        
        return ans;
    }
};