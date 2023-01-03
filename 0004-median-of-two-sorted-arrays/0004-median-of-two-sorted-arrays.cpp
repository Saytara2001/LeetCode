class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int n = nums1.size(), m =  nums2.size();
        int l1 =0, l2 = 0;
        nums1.push_back(1e8); 
        nums2.push_back(1e8);
        while( l1 < n || l2 < m){
            if(nums1[l1] < nums2[l2]) v.push_back(nums1[l1++]);
            else v.push_back(nums2[l2++]);
        }
        double ans=0.0;
        if((n+m)&1) ans = v[(n+m)/2];
        else ans = (v[(n+m)/2] + v[(n+m)/2 -1]) /2.0;
        return ans;
    }
};