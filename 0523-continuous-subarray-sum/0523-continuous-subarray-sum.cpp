class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> pref;
        pref[0] = 0;
        int n = size(nums);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % k;
            if(pref.count(sum)) {
                if((i + 1) - pref[sum] > 1)
                    return true;
            }else {
                pref[sum] = i + 1;
            }
        }
        return false;
    }
};