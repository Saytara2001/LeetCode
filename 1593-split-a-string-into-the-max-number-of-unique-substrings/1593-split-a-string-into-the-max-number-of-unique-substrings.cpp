class Solution {
public:
    int rec(int i, string& s, unordered_set<string> vis) {
        
        if(i == size(s)) 
            return 0;
    
        int maxUnique = 0;
        
        for(int end = i + 1; end <= s.size(); end++) {
            
            string sub = s.substr(i, end - i);

            if(vis.find(sub) == vis.end()) {
                vis.insert(sub);
                maxUnique = max(maxUnique, 1 + rec(end, s, vis));
                vis.erase(sub);
            }
        }
        
        return maxUnique;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> vis;
        return rec(0, s, vis);
    }
};