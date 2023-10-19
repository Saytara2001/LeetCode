class Solution {
public:
    string get(string& s) {
        string res = "";
        for(auto ss:s) {
            if(ss != '#') 
                res += ss;
            else if(res.size()){
                res.pop_back();
            }
        }
        return res;
    }
    bool backspaceCompare(string s, string t) {
        return get(s) == get(t);
    }
};