class Solution {
public:
    bool buddyStrings(string s, string goal) {
        bool freq[26] = {};
        bool equal = 0;
        vector<int> idx;
        for(int i = 0; i < size(s); i++) {
            if(freq[s[i]-'a'])
                equal = 1;
            freq[s[i]-'a'] = 1;
            if(s[i] != goal[i]) {
                idx.push_back(i);
            }
        }
        if(idx.size() == 2) {
            swap(s[idx.front()], s[idx.back()]);
            if(s == goal)
                return 1;
        }
        if(idx.size() == 0 and equal) {
            return 1;
        }
        return 0;
    }
};