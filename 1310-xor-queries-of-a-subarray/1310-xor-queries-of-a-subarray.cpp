class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = size(arr);
        vector<int> pref(n + 1);
        
        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] ^ arr[i];
        }
        
        vector<int> res;
        for(auto it: queries) {
            res.push_back(pref[it[1] + 1] ^ pref[it[0]]);
        }
        
        return res;
    }
};