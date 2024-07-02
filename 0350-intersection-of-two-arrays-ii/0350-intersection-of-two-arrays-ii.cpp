class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        int p1 = 0, p2 = 0;
        int n = size(nums1), m = size(nums2);
        vector<int> v;
        while(p1 < n and p2 < m) {
            if(nums1[p1] == nums2[p2]) {
                v.push_back(nums1[p1]);
                p1++;
                p2++;
            }else if(nums1[p1] > nums2[p2]) 
                p2++;
            else 
                p1++;
        }
        
        return v;
    }
};