class Solution {
public:
    typedef long long ll;
    int n, m;
    bool valid(ll mid, vector<int>& v) {
        int cnt = 1;
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            if (sum + v[i] <= mid) {
                sum += v[i];
            } else {
                sum = v[i];
                cnt++;
            }
        }
        return cnt <= m;
    }
    int splitArray(vector<int>& nums, int k) {
        ll mx = 0, sum = 0;
        n = size(nums);
        m = k;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            mx = max(mx, (ll) nums[i]);
        }
        ll l = mx, r = sum;
        ll ans = mx;
        while (l <= r) {
            ll mid = l + ((r - l) >> 1);
            if (valid(mid, nums)) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};