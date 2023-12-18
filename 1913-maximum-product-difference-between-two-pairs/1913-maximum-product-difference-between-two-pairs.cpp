class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int mx1 = 0, mx2 = 0, mn1 = 1e5, mn2 = 1e5;
        for(auto it: nums) {
            
            if(mx1 < it) {
                mx2 = max(mx1, mx2);
                mx1 = it;
            }else {
                mx2 = max(mx2, it);
            }
            
            if(mn1 > it) {
                mn2 = min(mn1, mn2);
                mn1 = it;
            }else {
                mn2 = min(mn2, it);
            }
        }
        return mx1 * mx2 - mn1 * mn2;
    }
};