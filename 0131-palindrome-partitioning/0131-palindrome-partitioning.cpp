class Solution {
public:
    bool isPlaindrome(string s){
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }
    void rec(int start, string& s, vector<string>& v, vector<vector<string>>& ans) {
        if(start == s.size()) {
            ans.push_back(v);
            return;
        }
        for(int end = start; end < s.size(); end++) {
            if(isPlaindrome(s.substr(start, end - start + 1))){
                v.push_back(s.substr(start, end - start + 1));
                rec(end+1, s,  v, ans);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        vector<vector<string>> ans;
        rec(0, s , v, ans);
        return ans;
    }
};