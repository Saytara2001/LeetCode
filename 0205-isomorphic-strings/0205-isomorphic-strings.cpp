class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s.size() != t.size()) return 0;
        unordered_map<char, char> mp1, mp2;
        
        for(int i = 0; i < s.size(); i++){
            if(!mp1.count(s[i]) and !mp2.count(t[i])){
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }else if(mp1[s[i]] != t[i] and mp2[t[i]] != s[i]) return 0;
        }
        return 1;
    }
};