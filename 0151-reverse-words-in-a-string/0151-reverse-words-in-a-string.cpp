class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> v;
        string tmp = "";
        
        for(auto it: s) {
            if(it != ' ') {
                tmp += it;
            }else {
                if(tmp.size())
                    v.push_back(tmp);
                tmp = "";
            }
        }
        
        if(tmp.size()) v.push_back(tmp);
        string ans = "";
        
        while(v.size()) {
            ans += v.back();
            ans += " ";
            v.pop_back();
        }
        
        if(ans.back() == ' ')
            ans.pop_back();
        
        return ans;
    }
};