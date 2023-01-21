class Solution {
public:
    vector<string> ans;
    bool valid(string t) {
        string tmp = "";
        t += '.';
        for(auto tt:t){
            if(tt == '.' and !tmp.empty()) {
                long long x = stoll(tmp);
                if(x >= 0 and x <= 255) tmp = "";
                else return 0;
            }else{
                if(!tmp.empty() and tmp[0] == '0') return 0;
                tmp += tt;
            }

        }
        return 1;
    }
    void rec(int i, int dots, string t, string& s){
        if(i == s.size()){
            if(dots == 0 and valid(t)){
                ans.push_back(t);
                return;
            }
            return;
        }

        if(!t.empty() and dots and t.back() != '.'){
            t += '.';
            rec(i, dots - 1, t, s);
            if(t.back() == '.') t.pop_back();
        }
        rec(i+1, dots, t + s[i], s);
    }
    vector<string> restoreIpAddresses(string s) {
         rec(0, 3, "", s);
        return ans;
    }
};