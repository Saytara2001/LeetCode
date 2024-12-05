class Solution {
public:
    bool canChange(string start, string target) {
        
        vector<pair<int, char>> pos1, pos2;
        int n = size(start);
        
        for(int i = 0; i < n; i++) {
            if(start[i] != '_')
                pos1.push_back({i, start[i]});
        }
        
        for(int i = 0; i < n; i++) {
            if(target[i] != '_')
                pos2.push_back({i, target[i]});
        }
        
        if(size(pos1) != size(pos2))
            return false;
        
        for(int i = 0; i < size(pos1); i++) {
            
            if(pos1[i].second != pos2[i].second)
                return false;
                
            if(pos1[i].first < pos2[i].first and pos1[i].second == 'L')
                return false;
            
            if(pos1[i].first > pos2[i].first and pos1[i].second == 'R')
                return false;
        }
        
        return true;
    }
};