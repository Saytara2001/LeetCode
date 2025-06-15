class Solution {
public:
    int maxDiff(int num) {
        int mx = num, mn = num;
        string s = to_string(num);
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] != '9') {
                char c = s[i];
                for(int j = i; j < n; j++) {
                    if(c == s[j]) s[j] = '9';
                }
                mx = stoi(s);
                break;
            }
        }
        s = to_string(num);
        
        if(count(begin(s), end(s), s[0]) == s.size())
            s = string(n, '1');
        else if(s[0] != '1') {
            char c = s[0];
            for(int j = 0; j < s.size(); j++) {
                if(c == s[j]) s[j] = '1';
            }
        } else {
            for(int i = 1; i < n; i++) {
                if(s[i] > '1') {
                    char c = s[i];
                    for(int j = 0; j < s.size(); j++) {
                        if(c == s[j]) s[j] = '0';
                    }
                    break;
                }
            }
        }
        mn = stoi(s);
        // cout << mx<< " " <<mn << endl;
        return mx - mn;
    }
};