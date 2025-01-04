class Solution {
public:
    bool ok(string& s, string& t) {
        int i = 0, j = 0;
        while(i < size(s) and s[i] == t[j]) {
            i++, j++;
        }
        int lst1 = size(s) - 1, lst2 = size(t) - 1;
        while(lst1 >= 0 and s[lst1] == t[lst2]) {
            lst1--, lst2--;
        }
        if(t[j] == t[lst2] and t[j] == '*')
            return true;
        return false;
    }
    bool hasMatch(string s, string p) {
        int n = size(s), m = size(p);
        for(int len = m - 1; len <= n; len++) {
            for(int i = 0; i + len <= n; i++) {
                string tmp = s.substr(i, len);
                if(ok(tmp, p))
                    return true;
            }
        }
        return false;
    }
};