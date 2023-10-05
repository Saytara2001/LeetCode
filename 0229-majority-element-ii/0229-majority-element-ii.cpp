class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //n log n
        vector<int> v;
        map<int, int> mp;
        for(auto it: nums) {
            mp[it]++;
        }
        for(auto it: mp)
            if(it.second > size(nums) / 3)
                v.push_back(it.first);
        return v;
    }
};