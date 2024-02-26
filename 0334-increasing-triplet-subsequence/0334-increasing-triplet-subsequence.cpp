class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = size(nums);
        vector<int> Mn(n), Mx(n);
        int mnNum = INT_MAX, mxNum = INT_MIN;
        for(int i = 0; i < n; i++) {
            mnNum = min(mnNum, nums[i]);
            Mn[i] = mnNum;
            mxNum = max(mxNum, nums[n - i - 1]);
            Mx[n - i - 1] = mxNum;
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] > Mn[i] and nums[i] < Mx[i])
                return true;
        }
        return false;
    }
};