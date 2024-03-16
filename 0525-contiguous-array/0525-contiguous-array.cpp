class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = size(nums);
        map<int, int> mp;
        mp[0] = -1;
        int sum = 0, mx = 0;
        for(int i = 0; i < n; i++) {
            sum += (nums[i] == 0 ? -1 : 1);
            if(mp.count(sum)) {
                mx = max(mx, i - mp[sum]);
            }else {
                mp[sum] = i;
            }
        }
        return mx;
    }
};