class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0]++;
        int n = size(nums), cnt = 0, sum = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            cnt += mp[sum - k];
            mp[sum]++;
        }
        
        return cnt;
    }
};