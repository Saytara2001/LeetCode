class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        //the idea is the parentheses is not valid, mark is with #
        int n = size(s);
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                open++;
            }
            if(s[i] == ')') {
                open ? open-- : s[i] = '#';
            }
        }
        for(int i = n - 1; i >= 0 and open; i--) {
            if(s[i] == '(') {
                s[i] = '#';
                open--;
            }
        }
        string res = "";
        for(auto it: s) {
            if(it != '#') res += it;
        }
        return res;
    }
};