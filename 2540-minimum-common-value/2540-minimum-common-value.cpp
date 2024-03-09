class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0;
        int n = size(nums1), m = size(nums2);
        while(p1 < n and p2 < m) {
            
            if(nums1[p1] == nums2[p2])
                return nums1[p1];
            
            if(nums1[p1] < nums2[p2])
                p1++;
            else 
                p2++;
        }
        return -1;
    }
};