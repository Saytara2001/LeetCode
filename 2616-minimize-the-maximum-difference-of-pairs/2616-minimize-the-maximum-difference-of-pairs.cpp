class Solution {
public:
    bool valid(vector<int>& v, int mid, int p) {
        int pairs = 0;
        int i = 0, n = size(v);
        while(i < n - 1) {
            if(v[i + 1] - v[i] <= mid) {
                pairs++;
                i++;
            }
            i++;
        }
        return pairs >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(begin(nums), end(nums));
        int l = 0, r = nums.back() - nums.front();
        int ans;
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            if(valid(nums, mid, p)) {
                ans = mid;
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        return ans;
    }
};