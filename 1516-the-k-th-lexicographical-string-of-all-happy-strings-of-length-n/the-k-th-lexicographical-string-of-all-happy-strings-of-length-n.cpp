class Solution {
public:
    int cnt = 0;
    string res = "";
    void rec(string &s, int n, int k) {
        if(s.size() == n) {
            ++cnt;
            if(cnt == k) res = s;
            return;
        }
        for(char x = 'a'; x <= 'c'; x++) {
            if(s.empty() or s.back() != x) {
                s.push_back(x);
                rec(s, n, k);
                s.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        string s = "";
        rec(s, n, k);
        return res;
    }
};