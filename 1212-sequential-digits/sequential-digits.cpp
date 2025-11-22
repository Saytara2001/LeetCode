class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int d = 1; d < 10; d++) {
            int gen = d, lst = d;
            while(gen <= high and lst < 10) {
                if(gen >= low) res.push_back(gen);
                gen *= 10;
                gen += ++lst;
            }
        }
        sort(begin(res), end(res));
        return res;
    }
};