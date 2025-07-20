class Solution {
public:
    int countTriplets(vector<int> &arr) {
        int n = size(arr);
        vector<int> pref(n + 2);
        for (int i = 1; i <= n; ++i) {
            pref[i] = pref[i - 1] ^ arr[i - 1];
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; ++j) {
                for (int k = j; k <= n; ++k) {
                    int b = pref[k] ^ pref[j - 1];
                    int a = pref[j - 1] ^ pref[i - 1];
                    cnt += (a == b);
                }
            }
        }
        return cnt;
    }
};
