class Solution {
public:
    bool judgeCircle(string moves) {
        int L = 0, U = 0;
        for(auto c: moves) {
            if(c == 'L') ++L;
            if(c == 'R') --L;
            if(c == 'U') ++U;
            if(c == 'D') --U;
        }
        return !L and !U;
    }
};