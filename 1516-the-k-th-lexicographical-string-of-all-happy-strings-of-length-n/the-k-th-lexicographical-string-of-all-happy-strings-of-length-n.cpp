class Solution {
public:
    int cnt = 0;
    string res = "";
    void rec(char prev, string s, int n, int k) {
        if(s.size() == n) {
            ++cnt;
            if(cnt == k) res = s;
            return;
        }
        for(char x = 'a'; x <= 'c'; x++) {
            if(prev != x) {
                rec(x, s + x, n, k);
            }
        }
    }
    string getHappyString(int n, int k) {
        rec('z', "", n, k);
        return res;
    }
};