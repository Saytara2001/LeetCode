class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int uni = 0, n = nums.size();
        vector<int> freq(2001);
        for(int i = 0; i < n; i++) {
            if(!freq[nums[i]]) {
                ++uni;
                freq[nums[i]]++;
            }
        }
        freq.assign(2001, 0);
        int cnt = 0;
        int l = 0, r = 0, dis = 0;
        while(l < n) {
            // move r
            while(r < n and dis < uni) {
                if(!freq[nums[r]]) {
                    ++dis;
                }
                freq[nums[r++]]++;
            }
            // check validality
            if(dis == uni) 
                cnt += n - r + 1;
            // move l  
            if(--freq[nums[l++]] == 0) {
                --dis;
            }
        }
        return cnt;
    }
};