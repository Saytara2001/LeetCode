class Solution {
public:
    int minLength(string s, int numOps) {
        int n = size(s);
        
        //try length 1 alternative (0101 or 1010)
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(i & 1) { 
                s[i] == '1' ? cnt1++ : cnt2++; //0101
            } else {
                s[i] == '0' ? cnt1++ : cnt2++; //1010
            }
        }
        
        if(cnt1 <= numOps or cnt2 <= numOps) 
            return 1;
        
        auto isValid = [&](int longestLength) {
            int k = numOps, need = 0;
            for(int i = 0; i < n; i++) {
                int cur = i;
                while(cur < n and s[cur] == s[i]) {
                    ++cur;
                }
                need += (cur - i) / (longestLength + 1);
                i = cur - 1;
            }
            return need <= numOps;
        };

        int l = 2, r = n;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(isValid(mid)) {
                r = mid;
            }else {
                l = mid + 1;
            }
        }
        return r;
    }
};