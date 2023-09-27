class Solution {
public:
    string decodeAtIndex(string s, int k) {
        string tmp = "";
        int n = size(s);
        long long sz = 0;
        int i = 0;
        for(i = 0; i < n and sz < k; i++) {
            if(s[i] >= 'a' and s[i] <= 'z')
                sz++;
            else
                sz *= (s[i] - '0');
        }

        for(int j = i - 1; j >= 0; j--) {
            
            if(s[j] >= 'a' and s[j] <= 'z') {
                if(k == 0 or k == sz) {
                    return string(1, s[j]);
                }
                sz--;
            }else {
                sz /= (s[j] - '0');
                k %= sz;
            }
        }
        return ""; //not reachable
    }
};