// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool valid(int n){
    return isBadVersion(n);
}
class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1 , r = n;
        while(r - l != 0){
            int mid = l + (r-l)/2;
            if(valid(mid)) r = mid;
            else l = ++mid;
        }
        return r;
    }
};