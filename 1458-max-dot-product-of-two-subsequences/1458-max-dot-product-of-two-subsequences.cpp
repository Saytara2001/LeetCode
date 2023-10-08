class Solution {
public:
    int dp[500][500];
    int rec(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if(i == size(nums1) or j == size(nums2))
            return 0;
        
        int &ret = dp[i][j];
        if(~ret)
            return ret;
        
        ret = rec(i + 1, j, nums1, nums2);
        ret = max(ret, rec(i, j + 1, nums1, nums2));
        ret = max(ret, rec(i + 1, j + 1, nums1, nums2) + (nums1[i] * nums2[j]));
        
        return ret;
        
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof dp);
        
        int mx1 = -2e9, mn1 = 2e9;
        int mx2 = -2e9, mn2 = 2e9;
        
        for (int num: nums1) {
            mx1 = max(mx1, num);
            mn1 = min(mn1, num);
        }
        
        for (int num: nums2) {
            mx2 = max(mx2, num);
            mn2 = min(mn2, num);
        }
        
        if (mx1 < 0 && mn2 > 0) {
            return mx1 * mn2;
        }
        
        if (mn1 > 0 && mx2 < 0) {
            return mn1 * mx2;
        } 
        return rec(0, 0, nums1, nums2);
    }
};