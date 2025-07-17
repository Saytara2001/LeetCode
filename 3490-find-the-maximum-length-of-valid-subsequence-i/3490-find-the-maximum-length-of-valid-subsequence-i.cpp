class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<vector<int>> v(2);
        int n = size(nums);
        for(int i = 0; i < n; i++) {
            v[nums[i] % 2].push_back(i);
        }
        int maxLen = max(v[0].size(), v[1].size());
        int i = 0, cnt = 1;
        while(true) {
            int need = 1 - (nums[i] % 2); // swap (0, 1)
            auto it = upper_bound(begin(v[need]), end(v[need]), i);
            if(it != end(v[need])) {
                i = *it;
                ++cnt;
            } else {
                break;
            }
        }
        maxLen = max(maxLen, cnt);
        return maxLen;
    }
};