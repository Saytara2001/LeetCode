class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {

        int lst = 0, n = size(derived);
        
        for(int i = 0; i < n - 1; i++) {
            if(derived[i] == 1) {
                lst ^= 1;
            }
        }

        if(lst == derived.back())
            return true;

        return false;
    }
};