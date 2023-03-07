typedef long long ll;
class Solution {
public:
    bool valid(int &totalTrips, ll mid, vector<int>& time) {
        __int128 trips = 0;
        for(auto vv:time) {
            trips += mid / vv;
        }
        return trips >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll l = 1, r = 1e16;
        while(l < r) {
            ll mid = l + ((r - l) >> 1);
            if(valid(totalTrips, mid, time))
                r = mid;
            else 
                l = mid + 1;
        }
        return r;
    }
};