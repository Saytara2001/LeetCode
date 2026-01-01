class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int rem = 1;
        for(int i = digits.size() - 1; i >= 0; i--) {
            int d = digits[i];
            digits[i] = (digits[i] + rem) % 10;
            rem = (d + rem) / 10;
        }
        if(rem > 0)
            digits.insert(begin(digits), rem);
        return digits;
    }
};