class Solution {
public:
    bool isBad(char a, int b) {
        if(tolower(a) != tolower(b)) return false;
        return a != b;
    }
    string makeGood(string s) {
        string res = "";
        for(auto it: s) {
            if(size(res) and isBad(res.back(), it)) {
                res.pop_back();
                continue;
            }
            res += it;
        }
        return res;
    }
};