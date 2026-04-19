class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int dis = 0;
        int n = nums1.size(), m = nums2.size();
        while(i < n and j < m) {
            if(nums1[i] <= nums2[j]) {
                dis = max(dis, j - i);
                ++j;
            } else {
                ++i;
            }
        }
        return dis;
    }
};