typedef long long ll;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<ll, int> mp;
        mp[0]++;
        ll sum = 0, nums_subarray = 0;
        for(int i = 0; i <nums.size(); i++){
            sum += nums[i];
            sum = ((sum % k) + k) % k;
            nums_subarray += mp[sum]++;
        }
        return nums_subarray;
    }
};