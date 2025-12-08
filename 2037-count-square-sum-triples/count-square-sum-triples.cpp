class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int val = i * i + j * j;
                int rt = sqrt(val);
                if(rt <= n and rt * rt == val) ++cnt;
            }
        }
        return cnt;
    }
};