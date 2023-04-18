class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int x = 0, y = 0;
        while(x < word1.size() or y < word2.size()) {
            
            if(x < word1.size())
                res += word1[x++];
            
            if(y < word2.size())
                res += word2[y++];
        }
        return res;
    }
};