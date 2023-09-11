class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = size(groupSizes);
        vector<vector<int>> res;
        vector<vector<int>> v(n + 1);
        for(int i = 0; i < size(groupSizes) ; i++) {
            v[groupSizes[i]].push_back(i);
            if(v[groupSizes[i]].size() == groupSizes[i]) {
                res.push_back(v[groupSizes[i]]);
                v[groupSizes[i]].clear();
            }
        }
        return res;
    }
};