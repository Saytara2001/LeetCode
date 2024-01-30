class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it: tokens) {
            if(it != "+" and it != "-" and it != "*" and it != "/") {
                cout << stoi(it) <<endl;
                st.push(stoi(it));
            }else {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if(it == "+") st.push(num2 + num1);
                if(it == "-") st.push(num2 - num1);
                if(it == "*") st.push(num2 * num1);
                if(it == "/") st.push(num2 / num1);
            }
        }
        return st.top();
    }
};