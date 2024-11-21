class Solution {
public:
    bool checkStrings(string s1, string s2) {
        
        vector<int> freq1(26), freq2(26);
        
        for(int i = 0; i < size(s1); i++) {
            if(i & 1) {
                freq1[s1[i] - 'a']++;
            }else {
                freq2[s1[i] - 'a']++;
            }
        }
        
        for(int i = 0; i < size(s2); i++) {
            if(i & 1) {
                if(--freq1[s2[i] - 'a'] < 0)
                    return false;
            }else {
                if(--freq2[s2[i] - 'a'] < 0)
                    return false;
            }
        }
        
        return true;
    }
};