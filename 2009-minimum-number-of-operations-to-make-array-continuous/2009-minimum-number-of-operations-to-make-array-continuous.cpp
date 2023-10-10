class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        set<int> s(begin(nums), end(nums));
        
        vector<int> v;
        for(auto it: s) {
            v.push_back(it);
        }
        
        int n = size(nums), mn = n;
        for(int i = 0; i < size(v); i++) {
            int j = upper_bound(begin(v), end(v), v[i] + n - 1) - begin(v);
            mn = min(n - (j - i), mn);
        }
        
        return mn;
    }
};