class Solution {
public:
    const int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        vector<int> v(2, 0);
        v[0] = 1;
        int prev = 0;
        long long sub = 0;
        for(auto x: arr) {
            int pref = (x + prev) & 1;
            sub = (sub + v[pref ^ 1]) % mod;
            v[pref]++;
            prev = pref;
        }
        return sub;
    }
};