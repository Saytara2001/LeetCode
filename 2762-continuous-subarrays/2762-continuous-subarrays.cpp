class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> ms;
        int n = size(nums);
        
        int l = 0;
        long long cnt = 0;
        for(int r = 0; r < n; r++) {
            ms.insert(nums[r]);
            if(*ms.rbegin() - *ms.begin() <= 2) {
                cnt += r - l + 1;
            }else {
                while(l < r and *ms.rbegin() - *ms.begin() > 2) {
                    ms.erase(ms.find(nums[l++]));
                }
                cnt += r - l + 1;
            }
        }
        
        return cnt;
    }
};