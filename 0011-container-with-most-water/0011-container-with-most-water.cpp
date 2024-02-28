class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, n = size(height);
        int l = 0, r = n - 1;
        while(l < r) {
            maxArea = max(maxArea, (r - l) * min(height[l], height[r]));
            height[l] < height[r] ? l++: r--;
        }
        return maxArea;
    }
};