class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> pos(26, 25);
        for(int i = 0; i < size(order); i++) {
            pos[order[i] - 'a'] = i;
        }
        sort(begin(s), end(s), [&](auto& a, auto& b) {
           return pos[a - 'a'] < pos[b - 'a']; 
        });
        return s;
    }
};