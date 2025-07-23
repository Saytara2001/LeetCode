class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(x > y) 
            reverse(begin(s), end(s));
        else 
            swap(x, y);
        
        int b = 0, a = 0, score = 0;
        for(int i = 0; i < size(s); i++) {
            if(s[i] == 'b') {
                ++b;
                continue;
            }
            if(s[i] == 'a') {
                if(b > 0) {
                    score += x;
                    --b;
                }else {
                    ++a;
                }
                continue;
            }
            score += min(a, b) * y; //take rem with ab
            a = b = 0;
        }
        score += min(a, b) * y; //take rem with ab
        return score;
    }
};