class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temps) {
        stack<int> st;
        int n = size(temps);
        
        vector<int> ans(n, 0);
        for(int i = n - 1 ; i >= 0; i--) {
            while(st.size() and temps[i] >= temps[st.top()]) st.pop();
            if(st.size()) ans[i] = st.top() - i;
            st.push(i);
            
        }

        return ans;
    }
};