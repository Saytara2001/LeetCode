class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res = "";
        int m = part.size();
        for(auto c: s) {
            res += c;
            int n = res.size();
            while(n >= m and res.substr(n - m, m) == part) {
                for(int cnt = 0; cnt < m; cnt++) 
                    res.pop_back();
            } 
        }

        return res;
    }
};