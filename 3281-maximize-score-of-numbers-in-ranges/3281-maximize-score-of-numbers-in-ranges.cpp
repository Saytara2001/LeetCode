class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        
        int n = size(start);
        sort(begin(start), end (start));
        
        auto valid = [&](int distance) {
            long long lst = start[0];
            for(int i = 1; i < n; i++) {
                if(lst + distance > start[i] + d)
                    return false;
                if(lst + distance <= start[i]) 
                    lst = start[i];
                else
                    lst += distance;
            }
            return true;
        };
        int l = 0, r = 2e9;
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