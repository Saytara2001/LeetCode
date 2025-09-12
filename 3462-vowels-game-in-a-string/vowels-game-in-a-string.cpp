class Solution {
public:
    bool doesAliceWin(string s) {
        // remove all odd | divide the even into 2 odd (1 + x)
        for(auto c: s) {
            if(c == 'a' or c == 'u' or c == 'o' or c == 'i' or c == 'e')
            return true;
        }
        return false;
    }
};