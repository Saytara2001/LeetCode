class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in(n);
        for(auto vv: edges) {
            in[vv[1]]++;
        }
        vector<int> nodes;
        for(int i = 0; i < n; i++) {
            if(!in[i])
                nodes.push_back(i);
        }
        return nodes;
    }
};