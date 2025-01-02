class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' or c == 'e' or c == 'o' or c == 'i' or c == 'u';
    }
    vector<int> vowelStrings(vector<string>& v, vector<vector<int>>& queries) {
        
        vector<int> pre(v.size() +1);
        for(int i = 0; i < v.size(); i++ ) {
            if(isVowel(v[i][0]) and isVowel(v[i].back()))
                pre[i+1]++;
        }
        for(int i = 1; i < pre.size(); i++) {
            pre[i] += pre[i-1];
        }
        vector<int> ans;
        for(auto qq:queries) {
            ans.push_back(pre[qq[1]+1] - pre[(qq[0])]);
        }
        return ans;
    }
};