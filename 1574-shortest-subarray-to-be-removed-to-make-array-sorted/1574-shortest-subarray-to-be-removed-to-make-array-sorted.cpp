class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        arr.insert(begin(arr), 0); // dummy value
        arr.push_back(1e9); // dummy value
        
        int n = size(arr);
        vector<int> inc(n);
        
        inc[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] <= arr[i + 1]) {
                inc[i] = 1;
            }else 
                break;
        }
        int shortest = n;
        for(int i = 0; i < n; i++) {
            
            if(i > 0 and arr[i] < arr[i - 1]) 
                break;
            
            int l = i, r = n;
            while(l < r) {
                int mid = l + (r - l) / 2;
                if(inc[mid] and arr[i] <= arr[mid]) {
                    r = mid;
                }else {
                    l = mid + 1;
                }
            }
            shortest = min(shortest, max(n - (i + 1) - (n - r), 0));
        }
        return shortest;
    }
};