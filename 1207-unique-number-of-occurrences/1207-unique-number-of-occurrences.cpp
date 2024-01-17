class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int, int> mp;
        vector<int> vis(size(arr) + 1);
        
        for(auto it: arr) {
            mp[it]++;
        }
        
        for(auto it: mp) {
            if(!vis[it.second]) {
                vis[it.second] = true;
                continue;
            }
            return false;
        }
        
        return true;
    }
};