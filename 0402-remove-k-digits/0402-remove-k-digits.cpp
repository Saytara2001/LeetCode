class Solution {
public:
    string removeKdigits(string s, int k) {
        int n = size(s);
        stack<char> st;
        for(int i = 0; i < n; i++) {
            while(st.size() and st.top() > s[i] and k > 0) {
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(k > 0) {
            st.pop();
            k--;
        }
        string res = "";
        while(st.size()) {
            res += st.top();
            st.pop();
        }
        while(size(res) and res.back() == '0') res.pop_back();
        reverse(begin(res), end(res));
        if(res.empty()) res = "0";
        return res;
    }
};