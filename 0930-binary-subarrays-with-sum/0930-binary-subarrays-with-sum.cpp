class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        map<int, int> mp;
        int ans = 0;
        
        mp[0]++;
        
        ans += mp[nums[0] - goal];
        mp[nums[0]]++;
        
        for(int i = 1; i < size(nums); i++) {
            nums[i] += nums[i - 1];
            ans += mp[nums[i] - goal];
            mp[nums[i]]++;
        }
        return ans;
    }
};