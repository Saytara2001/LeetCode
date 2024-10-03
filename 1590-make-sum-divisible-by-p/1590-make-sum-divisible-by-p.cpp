class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int n = size(nums);
        vector<int> suff(n + 2);
        for(int i = n - 1; i >= 0; i--) {
            suff[i] = (suff[i + 1] + nums[i]) % p;
        }
        
        // preprocess for indcies of prefix sum
        map<int, vector<int>> pos;
        for(int i = 0; i < n; i++) {
            pos[suff[i]].push_back(i);
        }
        pos[0].push_back(n);
        
        int pref = 0, mn = n;
        
        auto it = upper_bound(begin(pos[0]), end(pos[0]), 0);
        if(it != end(pos[0])) {
            mn = min(mn, *it);
        }
        
        for(int i = 0; i < n; i++) {
            
            pref = (pref + nums[i]) % p;
            int need = (p - pref) % p;
            
            auto it = upper_bound(begin(pos[need]), end(pos[need]), i);
            
            if(it != end(pos[need])) {
                mn = min(mn, *it - i - 1);
            }
        }
        
        return mn == n ? -1 : mn;
    }
};