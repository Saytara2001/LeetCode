class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = size(tokens);
        int l = 0, r = n - 1;
        int mx = 0, score = 0;
        sort(begin(tokens), end(tokens));
        while(l <= r) {
            if(power >= tokens[l]) {
                power -= tokens[l++];
                score++;
            }else if(score){
                power += tokens[r--];
                score--;
            }else {
                break;
            }
            mx = max(mx, score);
        }
        return mx;
    }
};