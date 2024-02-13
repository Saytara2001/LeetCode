class Solution {
public:
    string firstPalindrome(vector<string>& words) {
       for(auto word: words) {
           bool ok = true;
           int n = size(word);
           for(int i = 0; i < n / 2; i++) {
               ok &= word[i] == word[n - i - 1];
           }
           if(ok) return word;
       } 
        return "";
    }
};