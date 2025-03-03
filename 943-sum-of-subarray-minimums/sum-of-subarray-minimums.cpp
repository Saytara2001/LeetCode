class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum = 0, mod = 1e9 + 7;
        int n = size(arr);
        vector<array<int, 2>> stk; // idx, val
        for(int i = 0; i < n; i++) {
            while(stk.size() and stk.back()[1] >= arr[i]) {
                auto lst = stk.back();
                stk.pop_back();

                int r = i - lst[0];
                int l = stk.empty() ? lst[0] + 1 : lst[0] - stk.back()[0];
                
                sum += 1LL * l * r * lst[1] % mod;
                sum %= mod;
            }
            stk.push_back({i, arr[i]});
        }
        // 1 2 4
        for(int i = 0; i < size(stk); i++) {
            int r = n - stk[i][0];
            int l = i > 0 ? stk[i][0] - stk[i - 1][0] : stk[i][0] + 1;
            sum += 1LL * l * r * stk[i][1] % mod;
            sum %= mod;
        }
        return sum;
    }
};