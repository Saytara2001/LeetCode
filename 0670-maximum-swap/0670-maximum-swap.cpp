class Solution {
public:
    int maximumSwap(int num) {
        
        string s = to_string(num);
        int i = 0, n = size(s);
        vector<int> lstSeen(10);   
        
        for(int i = 0; i < n; i++)
            lstSeen[s[i] - '0'] = i;
        
        string t = s;
        sort(begin(t), end(t), greater<>());
        
        for(int i = 0; i < n; i++) {
            if(s[i] != t[i]) {
                swap(s[i], s[lstSeen[t[i] - '0']]);
                break;
            }
        }
        return stoi(s);
    }
};