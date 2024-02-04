class Solution {
public:
    string minWindow(string s, string t) {
        
        int rem = size(t);
        vector<int> freqHave(200), freqAll(200);
        
        for(auto c: t) {
            freqAll[c - 'A']++; 
        }
        
        int l = 0, r = 0, mnLength = 2e5, n = size(s);
        int start = -1;
        while(l <= r and l < n) {
            
            while(r < n and rem > 0) {
                if(freqHave[s[r] - 'A'] < freqAll[s[r] - 'A']) {
                    rem--;
                }
                freqHave[s[r] - 'A']++;
                r++;
            }
            
            //now its valid
            if(rem == 0 and mnLength > r - l) {
                mnLength = r - l;
                start = l;
            }
            
            if(freqHave[s[l] - 'A'] <= freqAll[s[l] - 'A']) {
                rem++;
            }
            freqHave[s[l] - 'A']--;
            l++;
        }
        string ans = start == -1 ? "" : s.substr(start, mnLength);
        return ans;
    }
};