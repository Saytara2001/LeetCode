class Solution {
public:
    int specialArray(vector<int>& nums) {
        vector<int> freq(1001);
        int n = size(nums);
        for(int i = 0; i < n; i++) {
            ++freq[nums[i]];
        }
        int all = n;
        for(int i = 0; i < 1001; i++) {
            if(all == i) {
                return i;
           }
           all -= freq[i];
        }
        return -1;
    }
};