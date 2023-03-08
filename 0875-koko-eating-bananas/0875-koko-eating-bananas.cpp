typedef long long ll;
class Solution {
public:
    bool valid(ll mid, vector<int>& piles, int h) {
        __int128 hours = 0;
        for(auto vv:piles) {
            hours += vv < mid ? 1 : vv / mid;
            if(vv > mid and vv % mid != 0)
                hours++;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        ll l = 1, r = 1e17;
        while(l < r) {
            ll mid = l + ((r - l) >> 1);
            if(valid(mid, piles, h))
                r = mid;
            else
                l = ++mid;
        }
        return r;
    }
};