class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<string, bool> mp;
        sort(s1.begin(), s1.end());
        for(int i = 0; i+s1.size() <= s2.size(); i++) {
            string tmp = s2.substr(i, s1.size());
            sort(tmp.begin(), tmp.end());
            mp[tmp] = 1;
            if(mp[s1]) return true;
        }
        return false;
    }
};