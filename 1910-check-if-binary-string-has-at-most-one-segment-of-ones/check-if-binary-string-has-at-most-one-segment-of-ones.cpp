class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int ones = 0, st = -1, end = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                if(st == -1) st = i;
                end = i;
                ++ones;
            }
        }
        return st == -1 or (end - st + 1 == ones);
    }
};