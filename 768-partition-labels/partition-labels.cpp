class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = size(s);
        vector<int> freq(26);
        for(auto c: s) {
            ++freq[c - 'a'];
        }
        int lst = -1;
        vector<int> res, have(26);
        for(int i = 0; i < n; i++) {
            --freq[s[i] - 'a'];
            have[s[i] - 'a'] = 1;
            // try to partition
            bool ok = true;
            for(int j = 0; j < 26; j++) {
                if(have[j] > 0) {
                    ok &= (freq[j] == 0);
                    if(!ok) break;
                }
            }
            if(ok) {
                res.push_back(i - lst);
                lst = i;
                have.assign(26, 0);
            }
        }
        return res;
    }
};