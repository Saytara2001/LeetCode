class Solution {
public:
    bool isDigit(string s) {
        for(int i = 0; i < size(s); i++) {
            if(s[i] < '0' or s[i] > '9') {
                return false;
            }
        }
        return true;
    }
    string decodeString(string s) {
        stack<string> st;
        int n = size(s);
        for(int i = 0; i < n; i++) {
            if(s[i] == ']') {
                string tmp = "";
                //remove encoded string
                while(st.top() != "[") {
                    tmp = st.top() + tmp;
                    st.pop();
                }
                st.pop(); //remove open bracket ==> [
                //remove number
                int rep = 0, pow = 1;
                while(st.size() and isDigit(st.top())) {
                    cout << st.top() <<" " << 2222<< endl;
                    rep += pow * stoi(st.top());
                    pow *= 10;
                    st.pop();
                }
                //generate string
                string gen = "";
                for(int j = 0; j < rep; j++) gen += tmp;
                st.push(gen);
            }else {
                string t = "";
                t += s[i];
                st.push(t);
            }
        }
        string ans = "";
        while(st.size()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};