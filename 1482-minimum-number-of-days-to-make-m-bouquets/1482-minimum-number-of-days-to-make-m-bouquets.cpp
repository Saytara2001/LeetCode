class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = size(bloomDay);
        
        if(n < 1LL * m * k)
            return -1;
        
        auto valid = [&](int day) ->bool {
            int cnt = 0, res = 0;
            for(int i = 0; i < n; i++) {
                if(bloomDay[i] <= day) {
                    cnt++;
                }else {
                    res += cnt / k;
                    cnt = 0;
                }
            }
            res += cnt / k;
            return res >= m;
        };
        int mx = *max_element(begin(bloomDay), end(bloomDay));
        int l = 1, r = mx;
        while(l < r) {
            
            int mid = (l + r)/ 2;
            if(valid(mid)) {
                r = mid;
            }else {
                l = mid + 1;
            }
            
        }
        
        return r;
    }
};