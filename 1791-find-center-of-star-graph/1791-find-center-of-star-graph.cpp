class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = size(edges);
        vector<int> v(n + 2);
        for(auto it: edges) {
            
            if((++v[it[0]]) == n)
                return it[0];
            
            if((++v[it[1]]) == n)
                return it[1];
        }
        
        return 1;
    }
};