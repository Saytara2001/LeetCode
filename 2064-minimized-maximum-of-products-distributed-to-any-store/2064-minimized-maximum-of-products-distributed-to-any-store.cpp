class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int m = size(quantities);
        auto valid = [&](int x) {
            int stores = 0;
            for(int i = 0; i < m; i++) {
                stores += (quantities[i] + x - 1) / x;
            }
            return stores <= n;
        };
        
        int l = 1, r = 1e5;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(valid(mid)) {
                r = mid;
            }else {
                l = mid + 1;
            }
        }
        return r;
    }
};