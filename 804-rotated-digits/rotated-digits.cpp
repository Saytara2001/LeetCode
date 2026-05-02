class Solution {
public:
    int rotatedDigits(int n) {
        auto rotate = [&](char c) {
            if(c == '0' or c == '1' or c == '8')
                return c;
            if(c == '2' or c == '5')
                return char('7' - c + '0');

            if(c == '6')
                return '9';
            if(c == '9')
                return '6';  

            return '?';
        };
        int good = 0;
        for(int i = 1; i <= n; i++) {
            string cur = to_string(i);
            bool can = true;
            for(auto &c: cur) {
                char r = rotate(c);
                if(r == '?') {
                    can = false;
                    break;
                }
                c = r;
            }
            if(can and cur != to_string(i)) ++good;
        }
        return good;
    }
};