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
        int lstFreq = 1e5;
        int del = 0;
        while(rem.size()) {
            if(rem.back() > lstFreq) {
                del += rem.back() - lstFreq;
            }
            lstFreq = min(lstFreq, rem.back());
            while(vis[lstFreq] and lstFreq > 0) {
                lstFreq--;
                del++;
            }
            vis[lstFreq] = 1;
            rem.pop_back();
        }
        return del;
    }
};