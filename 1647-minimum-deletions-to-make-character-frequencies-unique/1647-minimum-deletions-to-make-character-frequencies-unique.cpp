class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        for(auto it: s) {
            freq[it - 'a']++;
        }
        bool vis[100001] = {0};
        vector<int> rem;
        for(int i = 0; i < 26; i++) {
            if(freq[i]) {
                if(!vis[freq[i]])
                    vis[freq[i]] = 1;
                else
                    rem.push_back(freq[i]);
            }
        }
        sort(rem.begin(), rem.end());
        int del = 0;
        while(rem.size()) {
            int back = rem.back();
            rem.pop_back();
            while(vis[back] and back > 0) {
                back--;
                del++;
            }
            vis[back] = 1;
        }
        return del;
    }
};