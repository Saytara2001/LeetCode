class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int mx = 0, cuts = 0;
        int n = size(arr);
        
        for(int i = 0; i < n; i++) {
            mx = max(mx, arr[i]);
            cuts += mx == i; // because the arr is  permutation
        }
        
        return cuts;
    }
};