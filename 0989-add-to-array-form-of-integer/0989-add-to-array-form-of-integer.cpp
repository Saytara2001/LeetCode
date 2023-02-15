class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int carry = 0;
        for(int i = num.size()-1 ; i >= 0 ; i--) {
            int cal = num[i] + k % 10 + carry;
            carry = 0;
            k /= 10;
            if(cal > 9) {
                res.push_back(cal % 10);
                carry = cal/10;
            }else
                res.push_back(cal);
        }
        while(carry or k) {
            int cal = k % 10  + carry % 10;
            carry = 0;
            if(cal > 9) {
                res.push_back(cal % 10);
                carry = cal/10;
            }else
                res.push_back(cal);
            k /= 10;
        }
        if(carry) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};