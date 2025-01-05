class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = size(s);
        vector<int> pref(n + 1);
        for(int i = 0; i < size(shifts); i++) {
            pref[shifts[i][0]] += shifts[i][2] == 1 ? 1 : -1;
            pref[shifts[i][1] + 1] += shifts[i][2] == 1 ? -1 : 1;
        }

        for(int i = 0; i < n; i++) {
            if(i > 0) pref[i] += pref[i - 1];
            int op = pref[i] % 26;
            int cnt = abs(op);
            while(cnt--) {
                s[i] += (op > 0 ? 1 : -1);
                if(s[i] == 'a' - 1) {
                    s[i]  = 'z';
                }
                if(s[i] == 'z' + 1) {
                    s[i]  = 'a';
                }
            }
        }

        return s;
    }
};