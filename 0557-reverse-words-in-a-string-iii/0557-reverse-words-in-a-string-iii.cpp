class Solution {
public:
    string reverseWords(string s) {
        string ans = "", temp = "";
        for(int i = s.size()- 1; i >= 0; i--) {
            if(s[i] != ' ')
                temp += s[i];
            else {
                if(!ans.empty())
                    ans = " " + ans;
                ans = temp + ans;
                temp = "";
            }
        }
        
        if(temp.size()) {
            if(!ans.empty())
                    ans = " " + ans;
                ans = temp + ans;
        }
        return ans;
    }
};