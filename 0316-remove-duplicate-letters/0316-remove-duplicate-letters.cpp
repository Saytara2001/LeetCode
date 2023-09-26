class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n = s.size();
        stack<char> st;
        vector<int> freq(26);
        vector<bool> have(26);
        
        for(auto ss: s) 
            freq[ss - 'a']++;
        
        for(int i = 0; i < n; i++) {
            if(have[s[i] - 'a']) {
                freq[s[i] - 'a']--;
                continue;
            }
            //keep this increasing + freq if this only char
            while(st.size() and st.top() > s[i] and freq[st.top() - 'a'] > 0) {
                have[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(s[i]);
            have[s[i] - 'a'] = 1;
            freq[s[i] - 'a']--;
        }
        
        string ans = "";
        while(st.size()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};