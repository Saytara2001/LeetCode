class Solution {
public:
    string reversePrefix(string word, char ch) {
        int p = -1;
        for(int i = 0; i < size(word); i++) {
            if(word[i] == ch) {
                p = i;
                break;
            }
        }
        if(~p) {
            for(int i = 0; i < p; i++) {
                swap(word[i], word[p]);
                p--;
            }
        }
        return word;
    }
};