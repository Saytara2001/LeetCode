class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>> v;
        for(auto point:points)
            v.push_back({point[0], point[1]});
        sort(v.begin(), v.end());
        int i = 0, arrows = 0, n = v.size();
        while(i < n){
            int y = v[i].second;
            while(i < n and y >= v[i].first){
                y = min(y , v[i].second);
                i++;
            }
            arrows++;
        }
        return arrows;
    }
};