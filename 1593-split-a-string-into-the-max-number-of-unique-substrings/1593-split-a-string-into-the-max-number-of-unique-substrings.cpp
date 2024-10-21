class Solution {
public:
    int maxUnique = 0;
    string str;
    void rec(int i, string s, map<string, int> mp) {
        if(i == size(str)) {
            int add = (size(s) and mp.find(s) == end(mp));
            maxUnique = max(maxUnique, int(size(mp)) + add);
            return;
        }
        
        // continue
        s.push_back(str[i]);
        rec(i + 1, s, mp);
        s.pop_back();
        
        // split
        if(s.size()) { // non-empty string
            mp[s]++;
            rec(i + 1, str.substr(i, 1), mp);
            mp[s]--;
        }
    }
    int maxUniqueSplit(string s) {
        str = s;
        map<string, int> mp;
        rec(0, "", mp);
        return maxUnique;
    }
};