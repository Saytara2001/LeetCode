class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i= 1; i + 1 < size(arr); i++) {
            bool ok = (arr[i - 1] & 1) and  (arr[i] & 1) and (arr[i + 1] & 1);
            if(ok)
                return true;
        }
        return false;
    }
};