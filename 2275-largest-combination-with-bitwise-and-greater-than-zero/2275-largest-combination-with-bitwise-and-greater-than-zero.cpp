class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bit(29, 0);
        int mx = 0;
        for(int i = 0; i < size(candidates); i++) {
            for(int mask = 0; mask < 29; mask++) {
                if(candidates[i] & (1 << mask)) {
                    mx = max(mx, ++bit[mask]);
                }
            }
        }
        return mx;
    }
};