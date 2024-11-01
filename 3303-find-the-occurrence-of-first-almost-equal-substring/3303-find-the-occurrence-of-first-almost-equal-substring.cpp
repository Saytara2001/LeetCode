class Solution {
public:
    vector<int> z_function(string &s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    int minStartingIndex(string s, string pattern) {
        
        int n = size(s), m = size(pattern);
        
        string t = pattern + "#" + s;
        vector<int> z1 = z_function(t);
        
        reverse(s.begin(), s.end());
        reverse(pattern.begin(), pattern.end());
        
        t = pattern + "#" + s;
        vector<int> z2 = z_function(t);
        
        int R = n + 1;
        for(int L = m + 1; L < size(z1) and t[R] != '#'; L++, R--) {
            if(z1[L] + z2[R] + 1 >= m) {
                return L - m - 1;
            }
        }
        return -1;
    }
};