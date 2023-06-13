class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int> ,int > mp;
        for(int i = 0; i < grid.size(); i++) {
            mp[grid[i]]++;
        }
        int pairs = 0;
        for(int i = 0; i < grid.size(); i++) {
            vector<int> res;
            for(int j = 0 ; j < grid[i].size(); j++) {
                res.push_back(grid[j][i]);
            }
            if(mp.find(res) != mp.end())
                pairs += mp[res];
        }
        return pairs;
    }
};