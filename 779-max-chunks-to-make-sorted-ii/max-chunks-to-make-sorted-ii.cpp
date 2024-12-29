class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = size(arr), cuts = 0;
        vector<int> sortedArray = arr;
        sort(begin(sortedArray), end(sortedArray));
        
        long long s1 = 0, s2 = 0;
        for(int i = 0; i < n; i++) {
            s1 += sortedArray[i];
            s2 += arr[i];
            cuts += (s1 == s2);
        }
        return cuts;
    }
};