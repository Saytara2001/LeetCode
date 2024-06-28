class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> cost(n), deg(n);
        for(auto it: roads) {
            deg[it[0]]++;
            deg[it[1]]++;
        }
        sort(begin(deg), end(deg));
        long long tot = 0;
        for(int i = 0; i < n; i++) {
            tot += 1LL * deg[i] * (i + 1); 
        }
        return tot;
    }
};