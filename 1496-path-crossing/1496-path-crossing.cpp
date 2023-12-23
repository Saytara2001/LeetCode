class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> vis;
        int x = 0, y = 0;
        vis.insert({x, y});
        for(auto it: path) {
            if (it == 'N') y++;
            else if(it == 'S') y--;
            else if(it == 'E') x++;
            else x--;
            if(vis.count({x, y})) return true;
            vis.insert({x, y});
        }
        return false;
    }
};