class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' or c == 'o' or c == 'u' or c == 'i' or c == 'e');
    }
    string sortVowels(string s) {
        vector<char> rem;
        for(auto vv: s) {
            if(isVowel(tolower(vv)))
                rem.push_back(vv);
        }
        sort(begin(rem), end(rem));
        int idx = 0;
        for(auto &it: s) {
             if(isVowel(tolower(it)))
                 it = rem[idx++];
        }
        return s;
    }
};