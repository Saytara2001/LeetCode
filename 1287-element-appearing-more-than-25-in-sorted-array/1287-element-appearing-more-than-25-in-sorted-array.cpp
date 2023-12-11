class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = size(arr);
        for(int i = 0; i < n; i++) {
            int cur = i;
            while(cur < n and arr[cur] == arr[i]) {
                cur++;
            }
            if(1.0 * (cur - i) / n * 100 > 25)
                return arr[i];
            i = cur - 1;
        }
        return arr[0];
    }
};