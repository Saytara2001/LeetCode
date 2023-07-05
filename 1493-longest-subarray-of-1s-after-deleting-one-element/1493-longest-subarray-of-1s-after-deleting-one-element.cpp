class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int, int>> v;
        for(int i = 0; i < size(nums); ) {
            int cur = nums[i];
            int cnt = 0;
            while(i < size(nums) and cur == nums[i]) {
                cnt++;
                i++;
            }
            v.push_back({cur, cnt});
        }
        
        
        if(size(v) == 1 and v[0].first == 1) //1 1 1 1 1 
            return v[0].second - 1;
        
        int pre = 0, mx = 0;
        for(int i = 0; i < size(v) ; i++) {
            if(v[i].first == 0 and v[i].second > 1)
                pre = 0;
            if(v[i].first == 1) {
                mx = max(mx, pre + v[i].second);
                pre = v[i].second;
            }
        }
        return mx;
    }
};