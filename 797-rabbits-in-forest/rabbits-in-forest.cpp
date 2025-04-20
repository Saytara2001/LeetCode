class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for(auto x: answers) {
            ++mp[x];
        }
        int n = 0;
        for(auto [x, freq]: mp) {
            // freq / x + 1 with ceiling
            int calc = (freq + x) / (x + 1);
            n += max(calc * (x + 1), x + 1);
        }
        return n;
    }
};