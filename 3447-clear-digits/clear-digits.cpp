class Solution {
public:
    string clearDigits(string s) {
        string res = "";
        for(auto it: s) {
            if(isdigit(it) and res.size()) {
                res.pop_back();
            } else {
                res += it;
            }
        }
        return res;
    }
};