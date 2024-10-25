class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        sort(begin(folder), end(folder));
        
        vector<string> res;
        unordered_set<string> vis;
        
        for(auto path: folder) {
            
            string cur = "";
            bool ok = true;
            for(auto c: path) {
                if(c == '/' and size(cur) and vis.find(cur) != end(vis)) {
                    ok = false;
                }
                cur += c;
                
            }
            if(ok) {
                vis.insert(path);
                res.push_back(path);
            }
        }
        return res;
    }
};