class Solution {
public:
    int countOrders(int n) {
        long long ans = 1;
        int div = n;
        for(int i = 1; i <= 2 * n; i++) {
            ans *= (i % 2 == 0 ? 1LL * i / 2 : 1LL * i);
            ans %= 1000000007;
        }
        return ans;
    }
};