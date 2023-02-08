class Solution {
public:
    int jump(vector<int>& nums) {
        
        int cnt = 0, mx = 0, endRange = 0;
        
        for(int i = 0; i < nums.size() - 1; ++i) {
            
            mx = max(mx, nums[i] + i);
            
            if(i == endRange) {
                endRange = mx;
                cnt++;
            }
        }
        
        return cnt;
    }
};