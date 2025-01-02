class Solution {
public:
    int candy(vector<int>& v) {
        int n = size(v);
        vector<int> candy(n, 1);
        for(int i = 0; i < n; i++) {
            //check if child local minimum
            if((i - 1 < 0 or v[i] <= v[i - 1]) and (i + 1 >= n or v[i] <= v[i + 1])) {
                candy[i] = 1;
            }else if(i > 0 and v[i - 1] < v[i]) {
                candy[i] = candy[i - 1] + 1;
            }
        }
        
        for(int i = n - 2; i >= 0; i--) {
            if(v[i] > v[i + 1]) {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }

        int candies = accumulate(begin(candy), end(candy), 0);
        return candies;
    }
};