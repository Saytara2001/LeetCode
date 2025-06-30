class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto it: nums) {
            freq[it]++;
        }
        int mx = 0;
        for(auto [a, b]: freq) {
            if(freq.count(a + 1))
                mx = max(mx, b + freq[a + 1]);
        }
        return mx;
    }
};