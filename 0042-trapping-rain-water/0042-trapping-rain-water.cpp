class Solution { 
public:
    int trap(vector<int> &height) {
        int n = size(height);
        int l = 0, r = n - 1;
        int mxLeft = height[l], mxRight = height[r];
        long long water = 0;
        while(l < r) {
            if(mxLeft < mxRight) {
                l++;
                mxLeft = max(mxLeft, height[l]);
                water += mxLeft - height[l];
            }else {
                r--;
                mxRight = max(mxRight, height[r]);
                water += mxRight - height[r];
            }
        }
        return water;
    }
};