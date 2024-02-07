class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(100, 0);
        for(auto it: s) {
            freq[it - '0']++;
        }
        vector<pair<int, int>> vp;
        for(int i = 0; i < 100; i++) {
            if(freq[i] > 0) {
                vp.push_back({freq[i], i});
            }
        }
        sort(begin(vp), end(vp), greater<>());
        string ans = "";
        for(auto &[f, c]: vp) {
            for(int j = 0; j < f; j++)
                ans += (char)(c + '0');
        }
        return ans;
    }
};