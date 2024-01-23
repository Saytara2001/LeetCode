class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = size(arr);
        int mx = 0;
        for(int mask = 0; mask < (1 << n); mask++) {
            vector<bool> freq(26, 0);
            int cnt = 0;
            bool ok = true;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    for(auto c: arr[i]) {
                         if(freq[c - 'a']) {
                             ok = false;
                             break;
                         }
                        freq[c - 'a'] = true;
                    }
                    cnt += size(arr[i]);
                }
                if(!ok) break;
            }
            if(ok) 
                mx = max(mx, cnt);
        }
        return mx;
    }
};