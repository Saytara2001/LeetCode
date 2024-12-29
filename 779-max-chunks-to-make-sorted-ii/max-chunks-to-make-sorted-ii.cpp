class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        multiset<int> ms1, ms2;
        vector<int> sortedArray = arr;
        sort(begin(sortedArray), end(sortedArray));
        int n = size(arr), cuts = 0;;
        for(int i = 0; i < n; i++) {
            ms1.insert(sortedArray[i]);
            ms2.insert(arr[i]);
            cuts += (ms1 == ms2);
        }
        return cuts;
    }
};