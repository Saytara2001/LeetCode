class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        multiset<int> ms;
        for(auto array: arrays) {
            ms.insert(array.front());    
            ms.insert(array.back());
        }
        
        int mx = 0;
        for(auto array: arrays) {
            int x = array.front();  
            int y = array.back();
            ms.erase(ms.find(array.front()));    
            ms.erase(ms.find(array.back()));    
            if(ms.size()) {
                 mx = max(mx, abs(x - *ms.rbegin()));  
                 mx = max(mx, abs(y- *ms.begin()));
            }
        }
        
        return mx;
    }
};