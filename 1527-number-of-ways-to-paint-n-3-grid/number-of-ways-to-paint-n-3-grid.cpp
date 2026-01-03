class Solution {
public:
    int numOfWays(int n) {
        long long aba = 6;
        long long abc = 6;
        const int mod = 1e9 + 7;
        for(int i = 2; i <= n; i++) {
            long long abaNew = (3 * aba + 2 * abc) % mod;
            long long abcNew = (2 * aba + 2 * abc) % mod;
            aba = abaNew;
            abc = abcNew;
        }
        return (aba + abc) % mod;
    }
};