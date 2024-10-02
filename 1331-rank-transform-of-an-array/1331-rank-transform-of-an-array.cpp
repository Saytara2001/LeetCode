class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector<int> v = arr;
        sort(begin(v), end(v));
        map<int, int> mp;
        
        int n = size(v);
        int rank = 1;
        
        for(int i = 0; i < n; i++) {
            int cur = i;
            while(cur < n and v[i] == v[cur]) ++cur;
            mp[v[i]] = rank++;
            i = cur - 1;
        }
        
        for(int i = 0; i < n; i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};