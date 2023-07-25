class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int idx;
        int l = 1, r = size(v) - 2;
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            if(v[mid] > v[mid - 1] and v[mid] > v[mid + 1]) {
                idx = mid;
                break;
            }
            else if(v[mid] > v[mid - 1])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return idx;
    }
};