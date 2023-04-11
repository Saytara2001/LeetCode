class Solution {
public:
    string removeStars(string s) {
        
        string ans = "";
        for(auto ss : s) {
            if(ss == '*' and !ans.empty()) {
                ans.pop_back();
            }else
                ans += ss;
        }
        
        return ans;
    }
};