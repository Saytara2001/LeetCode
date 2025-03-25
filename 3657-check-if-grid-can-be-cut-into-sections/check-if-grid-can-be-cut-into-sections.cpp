class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {

        vector<pair<int, int>> segX, segY;

        for(auto rec: rectangles) {
            segX.emplace_back(rec[0], rec[2]);
            segY.emplace_back(rec[1], rec[3]);
        }

        sort(begin(segX), end(segX));
        sort(begin(segY), end(segY));

        auto canCut = [&](vector<pair<int, int>>& seg) -> bool{
            int lstEnd = 0;
            vector<pair<int, int>> merge;
            for(auto &[x, y] : seg) {
                if(x < lstEnd and merge.size()) {
                    int y2 = merge.back().second;
                    merge.back().second = max(y2, y);
                } else {
                    merge.emplace_back(x, y);
                }
                lstEnd = max(lstEnd, y);
            }
            return merge.size() > 2;
        };

        if(canCut(segX) or canCut(segY))
            return true;

        return false;
    }
};