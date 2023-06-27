class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& v1, vector<int>& v2, int k) {
        int n = size(v1), m = size(v2);
        vector<vector<int>> res;
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> vis;
        
        pq.push({-v1[0] - v2[0], {0 ,0}});
        vis.insert({0 ,0});
        while(k-- and !pq.empty()) {
            
            int i = pq.top().second.first; 
            int j = pq.top().second.second;
            pq.pop();
            
            res.push_back({v1[i], v2[j]});
            
            if(i + 1 < n and vis.find({i + 1, j}) == vis.end()) {
                int sum = -(v1[i + 1] + v2[j]);
                pq.push({sum, {i + 1, j}});
                vis.insert({i + 1, j});
            }
            if(j + 1 < m and vis.find({i, j + 1}) == vis.end()) {
                int sum = -(v1[i] + v2[j + 1]);
                pq.push({sum, {i, j + 1}});
                vis.insert({i, j + 1});
            }
        }
        return res;
    }
};