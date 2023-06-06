class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(begin(arr), end(arr));
        int pre = 0;
        for(int i = 1 ; i < arr.size(); i++) {
            if(i != 1 and pre != arr[i] - arr[i-1])
                return 0;
            pre = arr[i] - arr[i-1];
        }
        return 1;
    }
};