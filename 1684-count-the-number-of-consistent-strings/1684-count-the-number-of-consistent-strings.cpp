class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> freq(26);
        for(auto c: allowed) 
            freq[c - 'a'] = 1;
        
        int cnt = 0;
        for(auto word: words) {
            bool ok = true;
            for(auto c: word) {
                ok &= freq[c - 'a'];
            }
            if(ok) ++cnt;
        }
        return cnt;
    }
};