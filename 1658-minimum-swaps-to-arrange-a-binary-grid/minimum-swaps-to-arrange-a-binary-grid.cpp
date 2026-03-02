class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> v;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            int zeros = 0;
            for (int j = n - 1; j >= 0 and grid[i][j] == 0; j--) {
                ++zeros;
            }
            v.push_back(zeros);
        }
        int ans = 0;
        int need = n - 1; // number of zeros needed
        for(int i = 0; i < v.size() - 1 and need > 0; i++) {
            bool found = false;
            for(int j = i; j < v.size(); j++) {
                if(v[j] >= need) {
                    found = true;
                    for(int k = j; k > i; k--) {
                        swap(v[k], v[k - 1]);
                        ++ans;
                    }
                    --need;
                    break;
                }
            }
            if(!found) return -1;
        }
        return ans;
    }
};