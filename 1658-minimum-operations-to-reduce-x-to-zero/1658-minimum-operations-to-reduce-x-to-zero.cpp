class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //two pointers
        int all = accumulate(begin(nums), end(nums), 0);
        int n = size(nums), mn = (all == x ? n : 1e9);
        int l = 0, r = 0, have = 0;
        while(l <= r and r < n) {
            have += nums[r++];
            while(all - have < x and l < r) {
                have -= nums[l++];
            }
            if(all - have == x) {
                // cout << have <<" "<< all <<" "<<l <<" "<<r<<endl;
                mn = min(mn, n - (r - l));
            }
        }
        if(mn == 1e9) mn = -1;
        return mn;
    }
};