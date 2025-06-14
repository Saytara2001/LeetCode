class Solution {
public:
    int minMaxDifference(int num) {
        int mx = num, mn = 0;
        string s = to_string(num);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '9') {
                char c = s[i];
                for(int j = i; j < s.size(); j++) {
                    if(c == s[j]) s[j] = '9';
                }
                mx = stoi(s);
                break;
            }
        }
        s = to_string(num);
        char c = s[0];
        for(int j = 0; j < s.size(); j++) {
            if(c == s[j]) s[j] = '0';
        }
        mn = stoi(s);
        cout << mx <<" "<< mn << endl;
        return mx - mn;
    }
};