class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int, bool> mp1, mp2;
        for(auto vv:nums1) {
            mp1[vv] = 1;
        }
        for(auto vv:nums2) {
            mp2[vv] = 1;
        }
        vector<vector<int>> res;
        vector<int> ans;
        for(int i = 0; i < size(nums1); i++) {
            if(mp2[nums1[i]] == 0) {
                ans.push_back(nums1[i]);
                mp2[nums1[i]] = 1;
            }
        }
        res.push_back(ans);
        ans.clear();
        for(int i = 0; i < size(nums2); i++) {
            if(mp1[nums2[i]] == 0) {
                ans.push_back(nums2[i]);
                mp1[nums2[i]] = 1;
            }
        }
        res.push_back(ans);
        return res;
    }
};