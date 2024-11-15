class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = size(arr);
        
        int r = n - 1;
        while(r > 0 and arr[r - 1] <= arr[r]) 
            --r;
        
        int l = 0, shortest = r;
        while(l < r and (l == 0 or arr[l - 1] <= arr[l])) {
            // Find the next valid number
            while(r < n and arr[l] > arr[r]) {
                ++r;
            }
            shortest = min(shortest, r - l - 1);
            ++l;
        }
        return shortest;
    }
};