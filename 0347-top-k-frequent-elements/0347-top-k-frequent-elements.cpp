class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums) {
            mp[it]++;
        }
        vector<pair<int, int>> v;
        for(auto it:mp) {
            v.push_back({it.second, it.first});
        }
        sort(begin(v), end(v));
        vector<int> res;
        while(k--) {
            res.push_back(v.back().second);
            v.pop_back();
        }
        return res;
    }
};