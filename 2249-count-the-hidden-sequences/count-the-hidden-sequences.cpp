class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = size(differences);
        long long minPref = 2e18, maxPref = -2e18, pref = 0;
        for(int i = 0; i < n; i++) {
            pref += differences[i];
            minPref = min(minPref, pref);
            maxPref = max(maxPref, pref);
        }
        long long up = upper - maxPref > upper ? upper : upper - maxPref;
        long long low = lower - minPref < lower ? lower : lower - minPref;
        // if(low > up) 
        //     return 0;
        int cnt = max(up - low + 1, 0LL);
        return cnt;
    }
};