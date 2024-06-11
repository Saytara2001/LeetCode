class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        int n = size(arr2);
        vector<int> ind(1001);
        
        for(int i = 0; i < n; i++) {
            ind[arr2[i]] = i + 1;
        }
        
        for(int i = 0; i <= 1000; i++) {
            if(ind[i]) continue;
            ind[i] = n + i + 1;
        }
        
        sort(begin(arr1), end(arr1), [&](auto &x, auto &y) {
           return ind[x] < ind[y];
        });
        
        return arr1;
    }
};