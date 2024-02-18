class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0;
        set<char> st;
        for(auto i : s) st.insert(i);
        int szz = st.size();
        int n = s.size();
        for(int i = 0; i < n; i++) {
            int c = 0;
            bool mp[250] = {0};
            for(int j = i; j < min(n, i + szz); j++) {
                if(mp[s[j]]) break;
                mp[s[j]] = 1;
                c++;
            }
            mx = max(mx, c);
            if(mx == szz) break;
        }
        return mx;
    }
};