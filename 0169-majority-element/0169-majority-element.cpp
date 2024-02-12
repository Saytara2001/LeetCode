class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //n log n
        map<int, int> mp;
        for(auto it: nums) {
            mp[it]++;
        }
        for(auto it: mp)
            if(it.second > size(nums) / 2)
                return it.first;
        return 0;
    }
};