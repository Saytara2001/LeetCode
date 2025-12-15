class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long cnt = n;
        for (int i = 0; i < n; i++) {
            int cur = i + 1;
            while(cur < n and prices[cur] + 1 == prices[cur - 1]) {
                cur++;
            }
            int len = cur - i;
            cnt += 1LL * len * (len - 1) / 2; 
            i = cur - 1;
        }
        return cnt;
    }
};