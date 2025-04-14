class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int cnt = 0;
        int n = size(arr);
        for(int i=  0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    int ii = arr[i];
                    int jj = arr[j];
                    int kk = arr[k];
                    if(abs(ii - jj) <= a and abs(jj - kk) <= b and abs(ii - kk) <= c) 
                        ++cnt;
                }
            }
        }
        return cnt;
    }
};