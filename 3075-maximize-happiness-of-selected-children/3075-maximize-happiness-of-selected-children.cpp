class Solution {
public:
    long long maximumHappinessSum(vector<int>& v, int k) {
        long long res = 0;
        sort(begin(v), end(v), greater<>());
        int n = size(v);
        for(int i = 0; i < min(n, k); i++) {
            if(v[i] - i > 0) {
                res += v[i] - i;
            }else break;
        }
        return res;
    }
};