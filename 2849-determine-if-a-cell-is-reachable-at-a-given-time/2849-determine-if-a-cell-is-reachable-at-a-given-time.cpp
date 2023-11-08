class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(make_pair(sx, sy) == make_pair(fx, fy) and t == 1)
            return false;
        int minSteps = min(abs(sx - fx), abs(sy - fy));
        int rem = abs(sx - fx) - minSteps;
        rem += abs(sy - fy) - minSteps;
        return rem + minSteps <= t;
    }
};