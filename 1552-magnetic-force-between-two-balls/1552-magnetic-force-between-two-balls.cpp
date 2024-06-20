class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        
        int n = size(pos);
        sort(begin(pos), end(pos));
        
        auto valid = [&](int diff) -> bool {
            int pre = pos[0], balls = 1;
            for(int i = 1; i < n; i++) {
                if(pos[i] - pre >= diff) {
                    pre = pos[i];
                    balls++;
                }
            }
            return balls >= m;
        };
        
        int l = 0, r = pos.back() - pos.front();
        while(l < r) {
            int mid = l + (r - l + 1) / 2;
            if(valid(mid)) {
                l = mid;
            }else {
                r = mid - 1;
            }
        }
        return l;
    }
};