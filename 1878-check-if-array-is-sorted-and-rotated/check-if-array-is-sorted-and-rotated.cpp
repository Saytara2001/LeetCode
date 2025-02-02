class Solution {
public:
    bool check(vector<int>& v) {
        int mnIdx = 0, n = size(v);
        for(int i = 0; i < n; i++) {
            if(v[i] > v[(i + 1) % n]) {
                mnIdx = i + 1;
                break;
            }
        }
        for(int i = 0; i < n - 1; i++) {
            int a = v[(mnIdx + i) % n];
            int b = v[(mnIdx + i + 1) % n];
            if(a > b)
                return false;
        }
        return true;
    }
};