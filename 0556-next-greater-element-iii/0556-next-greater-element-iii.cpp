class Solution {
public:
    int nextGreaterElement(int n) {
        int m = n;
        int lst = -1;
        bool dec = true;
        while(m > 0) {
            dec &= (m % 10) >= lst;
            lst = m % 10;
            m /= 10;
        }
        if(dec) return -1;
        string t = to_string(n);
        next_permutation(begin(t), end(t));
        long long num = stoll(t);
        return num > INT_MAX ? -1 : num;
    }
};