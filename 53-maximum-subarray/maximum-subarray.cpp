class Solution {
public:
    int MaxCrossingSum(int l, int mid, int r, vector<int> &v) {
        int maxLeftSum = INT_MIN, maxRightSum = INT_MIN, sum = 0;
        for (int i = mid; i >= l; --i) {
            sum += v[i];
            maxLeftSum = max(maxLeftSum, sum);
        }
        sum = 0;
        for (int i = mid + 1; i <= r; ++i) {
            sum += v[i];
            maxRightSum = max(maxRightSum, sum);
        }
        return maxLeftSum + maxRightSum;
    }

    int MaxSum(int l, int r, vector<int> &v) {
        if (l > r)
            return INT_MIN;
        if (l == r)
            return v[l];

        int mid = l + (r - l) / 2;

        int leftSum = MaxSum(l, mid, v);
        int rightSum = MaxSum(mid + 1, r, v);
        int crossSum = MaxCrossingSum(l, mid, r, v);

        if (leftSum >= rightSum and leftSum >= crossSum)
            return leftSum;
        else if (rightSum >= leftSum and rightSum >= crossSum)
            return rightSum;
        else
            return crossSum;
    }
    int maxSubArray(vector<int>& nums) {
        return MaxSum(0, size(nums) - 1, nums);
    }
};