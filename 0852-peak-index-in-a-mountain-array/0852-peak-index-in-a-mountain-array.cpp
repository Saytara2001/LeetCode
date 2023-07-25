class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int idx;
        for(int i = 1; i < size(v) - 1; i++) {
            if(v[i] > v[i-1] and v[i] > v[i + 1]) {
                idx = i;
            }
        }
        return idx;
    }
};