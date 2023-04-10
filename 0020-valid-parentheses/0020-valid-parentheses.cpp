class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ss:s){
            if(ss == '{' or ss == '(' or ss == '[') st.push(ss);
            else{
                if(st.empty()) return 0;
                else{
                    if(ss == '}' and st.top() == '{') st.pop();
                    else if(ss == ']' and st.top() == '[') st.pop();
                    else if(ss == ')' and st.top() == '(') st.pop();
                    else return 0;
                }
            }
        }
        return st.empty();
    }
};