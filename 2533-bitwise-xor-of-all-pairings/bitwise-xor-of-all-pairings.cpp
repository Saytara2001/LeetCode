class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xr = 0;
        int n = size(nums1), m = size(nums2);
        
        if(m & 1) {
            for(auto x: nums1) xr ^= x;
        }
        
        if(n & 1) {
            for(auto x: nums2) xr ^= x;
        }

        return xr;
    }
};