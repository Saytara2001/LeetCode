class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        vector<vector<int>> ans(2);
        set<int> all;
        unordered_multiset<int> losers;
        
        for(auto it: matches) {
            all.insert(it[0]);
            all.insert(it[1]);
            
            losers.insert(it[1]);
        }
        
        for(auto it: all) {
            int cnt = losers.count(it);
            if(cnt == 0) {
                ans[0].push_back(it);
            }
            if(cnt == 1) {
                ans[1].push_back(it);
            }
        }
        
        return ans;
    }
};