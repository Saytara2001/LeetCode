class Solution {
public:
    string smallestNumber(string pattern) {

        stack<int> st;
        string res = "";

        int n = size(pattern) + 1;
        for(int i = 1; i <= n; i++) {
            st.push(i);

            if(pattern[i - 1] == 'I' or i == n) {
                while(st.size()) {
                    res += st.top() + '0';
                    st.pop();
                }
            }
        }

        return res;
    }
};