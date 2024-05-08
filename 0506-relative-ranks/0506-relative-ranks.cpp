class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = size(score);
        vector<pair<int ,int>> pos;
        
        for(int i = 0; i < n; i++) {
            pos.push_back({score[i], i});
        }
        sort(begin(pos), end(pos), greater<>());
        
        vector<string> res(n);
        for(int i = 0; i < n; i++) {
            int p = pos[i].second;
            if(i == 0) {
                res[p] = "Gold Medal";
            }else if(i == 1) {
                res[p] = "Silver Medal";
            }else if(i == 2) {
                res[p] = "Bronze Medal";
            }else {
                res[p] = to_string(i + 1); 
            }
        }
        return res;
    }
};