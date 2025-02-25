class Solution {
public:
    const int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        vector<int> v(2, 0);
        v[0] = 1;
        int pre = 0;
        long long sub = 0;
        for(auto x: arr) {
            int sum = (x + pre) & 1;
            sub = (sub + v[sum ^ 1]) % mod;
            v[sum]++;
            pre = sum;
        }
        return sub;
    }
};