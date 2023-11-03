class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int cur = 1;
        vector<string> res;
        for(int i = 0; i < size(target); i++) {
            if(cur == target[i]) {
                res.push_back("Push");
            }else {
                res.push_back("Push");
                res.push_back("Pop");
                i--;
            }
            cur++;
        }
        return res;
    }
};