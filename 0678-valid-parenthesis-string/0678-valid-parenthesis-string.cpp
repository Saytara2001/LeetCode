class Solution {
public:
    bool checkValidString(string s) {
        int n = size(s);
        stack<int> open, ast;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') open.push(i);
            if(s[i] == '*') ast.push(i);
            if(s[i] == ')') {
                if(open.size()) open.pop();
                else if(ast.size()) ast.pop();
                else return false;
            }
        }
        //handle this ==> **(( and  ((**
        while(open.size() and ast.size()) {
            if(open.top() > ast.top()) return false;
            open.pop();
            ast.pop();
        }
        return open.empty();
    }
};