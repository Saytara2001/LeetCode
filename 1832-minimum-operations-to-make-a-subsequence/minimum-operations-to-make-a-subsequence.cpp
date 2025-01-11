class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {

        int n = size(target), m = size(arr);
        unordered_map<int, int> pos;

        for(int i = 0; i < n; i++) {
            pos[target[i]] = i;
        }
        // get the needed elements only and its index
        vector<int> v;
        for(int i = 0; i < m; i++) {
            if(pos.find(arr[i]) != end(pos)) {
                v.push_back(pos[arr[i]]);
            }
        }
        // apply dp LIS to v on indcies
        vector<int> dp;
        for(int i = 0; i < size(v); i++) {
            auto it = lower_bound(begin(dp), end(dp), v[i]);
            if(it == end(dp)) {
                dp.push_back(v[i]);
            }else {
                *it = v[i];
            }
        }

        return n - int(dp.size());
    }
};