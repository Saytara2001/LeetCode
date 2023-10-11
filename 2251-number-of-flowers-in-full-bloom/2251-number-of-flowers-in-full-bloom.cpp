class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // solution with coordinate compression
        vector<int> indices;
        vector<int> pref(1000000);
        for(auto it: flowers) {
            indices.push_back(it[0]);
            indices.push_back(it[1]);
        }
        for(auto it: people) {
            indices.push_back(it);
        }
        //go compress and prefix
        sort(indices.begin(), indices.end());
	    indices.erase(unique(indices.begin(), indices.end()), indices.end());
        for(auto it: flowers) {
            int com = lower_bound(begin(indices), end(indices), it[0]) - begin(indices);
            pref[com]++;
            com = lower_bound(begin(indices), end(indices), it[1]) - begin(indices);
            pref[com + 1]--;
        }
        for(int i = 1 ; i < 1000000; i++) {
            pref[i] += pref[i - 1];
        }
        
        vector<int> res;
        for(auto it: people) {
            int com = lower_bound(begin(indices), end(indices), it) - begin(indices);
            res.push_back(pref[com]);
        }
        return res;
    }
};