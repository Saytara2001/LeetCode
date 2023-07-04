class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> mp;
        for(auto vv: nums) {
            mp[vv]++;
        }
        int ans = 0;
        for(auto vv: mp) {
            if(vv.second == 1) {
                ans =  vv.first;;
                break;
            }
        }
        return ans;
    }
};