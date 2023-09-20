class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //minimum and prefix
        int pre = 0, cnt = 0, n = size(nums);
        int i = 0;
        for( ;i < n; i++) {
            if(pre + nums[i] <= x) {
                pre += nums[i];
                cnt++;
            }else {
                i--;
                break;
            }
        }
        
        int mn = 1e9;
        if(pre == x)
            mn = min(mn, cnt);
        
        int r = n - 1;
        while(r >= 0 and i < r) {
            pre += nums[r--];
            cnt++;
            while(i >= 0 and pre > x) {
                pre -= nums[i--];
                cnt--;
            }
            if(pre == x)
                mn = min(mn, cnt);
        }
        return mn == 1e9 ? -1 : mn;
    }
};