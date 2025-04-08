class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        vector<int> freq(101);
        
        for(auto x: nums)
            freq[x]++;
        
        int all = 0;
        for(int i = 0; i <= 100; i++) 
            all += freq[i] > 1;
        
        int cnt = 0, n = size(nums);
        for(int i = 0; i < size(nums); i += 3) {
            if(all > 0) {
                cnt++;
                for(int j = i; j < min(n, i + 3); j++) {
                    if(--freq[nums[j]] == 1) --all;
                }
                if(all == 0) return cnt;
            }
        }
        
        return 0;
    }
};