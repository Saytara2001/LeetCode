class Solution {
public:
    string makeFancyString(string s) {
        int n = size(s);
        string res  = "";
        for(int i = 0; i < n; i++) {
            int cur = i;
            while(s[i] == s[cur]) {
                ++cur;
                if(cur - i < 3)
                    res += s[i];
            }
            i = cur - 1;
        }
        
        return res;
    }
};