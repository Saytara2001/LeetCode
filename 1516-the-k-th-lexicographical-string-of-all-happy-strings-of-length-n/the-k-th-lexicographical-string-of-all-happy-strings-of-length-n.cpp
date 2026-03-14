class Solution {
public:
    int cnt = 0;
    string res = "";
    void rec(string s, int n, int k) {
        if(s.size() == n) {
            ++cnt;
            if(cnt == k) res = s;
            return;
        }
        for(char x = 'a'; x <= 'c'; x++) {
            if(s.empty() or s.back() != x) {
                rec(s + x, n, k);
            }
        }
    }
    string getHappyString(int n, int k) {
        rec("", n, k);
        return res;
    }
};