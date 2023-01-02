class Solution {
public:
    bool detectCapitalUse(string word) {
        bool cap = false;
        int numsOfCapitals = 0, n = word.size();
        if(word[0] >= 'A' and word[0] <= 'Z') cap = true;
        for(auto ss:word){
            if(ss >= 'A' and ss <= 'Z') numsOfCapitals++;
        }
        return n == numsOfCapitals || !numsOfCapitals || (cap and numsOfCapitals == 1);
    }
};