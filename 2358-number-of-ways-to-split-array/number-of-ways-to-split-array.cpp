class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long sum = 0, pref = 0;
        for(auto it: nums) {
            sum += it;
        } 
        int splits = 0;
        for(auto it: nums) {
            pref += it;
            sum -= it;
            splits += pref >= sum;
        }
        return splits - (pref >= 0);
    }
};