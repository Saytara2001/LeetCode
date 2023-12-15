class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, bool> out;
        for(auto it: paths) {
            out[it[0]] = 1;
        }
        for(auto it: paths) {
             if(!out[it[0]]) {
                 return it[0];
             }
             if(!out[it[1]]) {
                 return it[1];
             }
        }
        return "";
    }
};