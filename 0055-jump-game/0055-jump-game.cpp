class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0, mx = 0, n = nums.size();
        while(i < n-1){
            mx = max(mx, nums[i++]);
            if(!mx) return 0;
            mx--;
        }
        return i == n-1;
    }
};