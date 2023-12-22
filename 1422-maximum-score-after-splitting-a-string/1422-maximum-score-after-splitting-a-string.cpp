class Solution {
public:
    int maxScore(string s) {
        int zeros = 0;
        int ones = count(begin(s), end(s), '1');
        int score = 0;
        for(int i = 0; i < size(s)- 1; i++) {
            s[i] == '0' ? zeros++ : ones--;
            score = max(score, zeros + ones);
        }
        return score;
    }
};