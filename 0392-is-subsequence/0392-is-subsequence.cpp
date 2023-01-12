class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0, idx2 = 0;
        while(idx < s.size() and idx2 < t.size()){
            if(s[idx] == t[idx2]) idx++;
            idx2++;
        }
        return idx == s.size();
    }
};