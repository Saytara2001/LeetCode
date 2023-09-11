class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = size(groupSizes);
        vector<vector<int>> v(n + 1);
        for(int i = 0; i < size(groupSizes) ; i++) {
            v[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for(int i = 1; i <= n ; i++) {
            vector<int> peoples;
            for(int j = 0 ; j < size(v[i]); j++) {
                peoples.push_back(v[i][j]);
                if(peoples.size() == i) {
                    res.push_back(peoples);
                    peoples.clear();
                }
            }
        }
        return res;
    }
};