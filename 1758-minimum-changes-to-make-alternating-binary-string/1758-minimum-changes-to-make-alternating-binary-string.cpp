class Solution {
public:
    int minOperations(string s) {
        int cnt = 0;
        for(int i = 0; i < size(s); i++) {
            if(i & 1) {
                cnt += (s[i] != '1');
            }else {
                cnt += (s[i] != '0');
            }
        }
        return (int) min(cnt, (int) size(s) - cnt);
    }
};