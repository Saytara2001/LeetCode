class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int p1 = 0, p2 = 0;
        int n = size(nums1), m = size(nums2);
        vector<vector<int>> res;
        while(p1 < n or p2 < m) {
            if(p1 < n and p2 < m) {
                if(nums1[p1][0] == nums2[p2][0]) {
                    res.push_back({nums1[p1][0], nums1[p1][1] + nums2[p2][1]});
                    ++p1, ++p2;
                } else if(nums1[p1][0] < nums2[p2][0]) {
                    res.push_back({nums1[p1][0], nums1[p1][1]});
                    ++p1;
                } else {
                    res.push_back({nums2[p2][0], nums2[p2][1]});
                    ++p2;
                }
            } else if(p1 < n){
                res.push_back({nums1[p1][0], nums1[p1][1]});
                ++p1;
            }else {
                res.push_back({nums2[p2][0], nums2[p2][1]});
                ++p2;
            }
        }
        return res;
    }
};