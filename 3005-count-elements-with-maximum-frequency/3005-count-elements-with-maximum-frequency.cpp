class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        int n = size(nums);
        vector<int> freq(101, 0);
        int mx = 0;
        for(auto it: nums) {
            if(mx < ++freq[it]) {
                mx = freq[it];
            }
            
        }
        int cnt = 0;
        for(int i = 1; i <= 100; i++) {
            if(mx == freq[i]) 
                cnt += freq[i];
        }
        return cnt;
    }
};