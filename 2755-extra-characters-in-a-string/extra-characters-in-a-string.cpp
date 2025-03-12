class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {

        int n = size(s);
        unordered_map<string, bool> mp;
        // map<pair<int, string>, int> dp;

        for(auto dict: dictionary) {
            mp[dict] = true;
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        function<int(int, int)> rec = [&](int l, int r) {

            if(r == n)  {
                return l == n ? 0 : 1000000;
            }
                
            int &ret = dp[l][r];
            if(~ret)
                return ret;

            int ch1 = rec(l, r + 1);

            string sub = s.substr(l, r - l + 1);
            int cost = mp.find(sub) == end(mp) ? sub.size() : 0;
            int ch2 = rec(r + 1, r + 1) + cost;
            
            return ret = min(ch1, ch2);
        };


        return rec(0, 0);
    }
};