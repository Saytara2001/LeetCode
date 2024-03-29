class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(begin(s), end(s));
        sort(begin(t), end(t));
        
        for(int i = 0; i < min(size(s), size(t)); i++) {
            if(s[i] != t[i])
                return t[i];
        }
        
        return t.back();
    }
};